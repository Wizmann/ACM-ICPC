#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int MAX_PRIME = 666;

typedef long long llint;

map<int, int> mp;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

vector<int> get_prime_factors(int p) {
    vector<int> res;
    for (int i = 2; i < MAX_PRIME; i++) {
        if (p % i == 0) {
            res.push_back(i);
        }
        while (p % i == 0) {
            p /= i;
        }
    }
    if (p != 1) {
        res.push_back(p);
    }
    return res;
}

llint do_solve1(int v, int p) {
    llint res = 0;
    vector<int> pf = get_prime_factors(p);
    assert(pf.size() < 15);
    int f = pf.size();
    for (int i = 1; i < (1 << f); i++) {
        int cnt = 0;
        int r = 1;
        for (int j = 0; j < f; j++) {
            if ((1 << j) & i) {
                cnt++;
                r *= pf[j];
            }
        }

        llint tot = 1LL * (1 + v / r) * (v / r) / 2 * r;
        if (cnt % 2 == 0) {
            res -= tot;
        } else {
            res += tot;
        }
    }
    return 1LL * (1 + v) * v / 2 - res;
}

llint solve1(int l, int r, int p) {
    return do_solve1(r, p) - do_solve1(l - 1, p);
}

llint solve2(int l, int r, int p) {
    llint res = 0;
    auto iter = mp.lower_bound(l);
    while (iter != mp.end() && iter->first <= r) {
        int pre = iter->first;
        int cur = iter->second;
        int b1 = gcd(pre, p);
        int b2 = gcd(cur, p);

        if (b1 == 1) {
            res -= pre;
        }
        if (b2 == 1) {
            res += cur;
        }
        ++iter;
    }
    return res;
}

llint solve(int l, int r, int p) {
    return solve1(l, r, p) + solve2(l, r, p);
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    while (T--) {
        mp.clear();
        int n, m;
        scanf("%d%d", &n, &m);

        int cmd;
        int a, b, c;
        while (m--) {
            scanf("%d", &cmd);
            if (cmd == 1) {
                scanf("%d%d%d", &a, &b, &c);
                print( solve(a, b, c));
            } else if (cmd == 2) {
                scanf("%d%d", &a, &b);
                mp[a] = b;
            } else {
                assert(false);
            }
        }
    }
    return 0;
}
