#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int MAXN = 1234567;
const int MOD = 1000000000 + 7;

vector<int> primes;

void init() {
    primes.push_back(2);
    primes.push_back(3);

    for (int i = 5; i < MAXN; i++) {
        bool flag = true;
        for (size_t j = 0; j < primes.size(); j++) {
            int cur = primes[j];
            if (1LL * cur * cur > i) {
                break;
            }

            if (i % cur == 0) {
                flag = false;
                break;
            }
        }

        if (flag) {
            primes.push_back(i);
        }
    }
}

class DisjointSet {
public:
    DisjointSet(int n_) : n(n_), father(n_) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }

    void make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);
        father[fb] = fa;
    }
private:
    int n;
    vector<int> father;
};

int n;
vector<int> ns;

llint fastpow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

llint solve() {
    sort(ns.begin(), ns.end(), greater<int>());

    int ones = 0;

    while (!ns.empty() && ns.back() == 1) {
        ones++;
        ns.pop_back();
    }

    vector<bool> nums(MAXN, false);

    for (auto num: ns) {
        nums[num] = true;
    }

    DisjointSet ds(MAXN);

    for (auto prime: primes) {
        int pre = -1;
        for (int i = 1; i * prime < MAXN; i++) {
            if (nums[i * prime]) {
                if (pre != -1) {
                    ds.make_union(pre, i * prime);
                }
                pre = i * prime;
            }
        }
    }

    set<int> st;
    for (auto num: ns) {
        st.insert(ds.find_father(num));
    }

    int u = ones + st.size();

    return (fastpow(2, u) + MOD - 2) % MOD;
}

int main() {
    init();

    int T;
    input(T);
    while (T--) {
        input(n);
        ns = vector<int>(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }
        printf("%lld\n", solve());
    }
    return 0;
}
