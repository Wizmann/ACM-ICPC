#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int MAXPRIME = 21;

vector<bool> sieve(MAXPRIME, true);
vector<int> primes;

template <int prec>
class BigInt {
public:
    BigInt() : num(prec / 10 + 1, 0) {}
    BigInt(uint32_t value) : BigInt() {
        num[0] = value;
    }

    void Print() {
        bool flag = true;
        for (int i = (int)num.size() - 1; i >= 0; i--) {
            if (flag && num[i] == 0) {
                continue;
            }
            if (flag && num[i]) {
                printf("%lld", num[i]);
                flag = false;
            } else {
                printf("%010lld", num[i]);
                flag = false;
            }
        }
    }

    void Println() {
        Print();
        puts("");
    }

    void Multiply(uint32_t x) {
        llint g = 0;
        for (int i = 0; i < (int)num.size(); i++) {
            num[i] = num[i] * x + g;
            g = num[i] / BASE;
            num[i] %= BASE;
        }
        assert(g == 0);
    }

private:
    static constexpr const llint BASE = 10'000'000'000;
    vector<llint> num;
};

void init() {
    for (int i = 2; i < MAXPRIME; i++) {
        if (sieve[i] == false) {
            continue;
        }
        for (int j = 2; 1LL * i * j < MAXPRIME; j++) {
            sieve[i * j] = false;
        }
    }

    for (int i = 2; i < MAXPRIME; i++) {
        if (sieve[i] == false) {
            continue;
        }
        primes.push_back(i);
    }
}

llint mypow(llint a, llint b) {
    llint res =  1;
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}

double mini = 1e100;
vector<int> factors;
vector<int> minipath;

void dfs(int n, int pre, int p, double cur, vector<int>& path) {
    if (n == 1) {
        if (cur < mini) {
            minipath = path;
            mini = cur;
        }
        return;
    }
    if (cur > mini) {
        return;
    }

    for (int i = pre; i < (int)factors.size(); i++) {
        if (n % factors[i] != 0) {
            continue;
        }

        path[p] = factors[i] - 1;
        dfs(n / factors[i], i, p + 1, cur + 1. * (factors[i] - 1) * log(primes[p]), path);
        path[p] = 0;
    }
}

int main() {
    init();

    int n;
    input(n);

    set<int> st;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            st.insert(i);
            st.insert(n / i);
        }
    }
    st.erase(st.find(1));

    for (auto num : st) {
        factors.push_back(num);
    }
    reverse(factors.begin(), factors.end());

    vector<int> path(primes.size(), 0);
    dfs(n, 0, 0, 0, path);

    /*
    for (int i = 0; i < (int)primes.size(); i++) {
        print(primes[i], minipath[i]);
    }
    */

    BigInt<30000> ans(1);
    for (int i = 0; i < (int)primes.size(); i++) {
        for (int j = 0; j < minipath[i]; j++) {
            ans.Multiply(primes[i]);
        }
    }
    ans.Println();


    return 0;
}

/*

^^^TEST^^^
4
-----
6
$$$TEST$$$

^^^TEST^^^
8
-----
24
$$$TEST$$$

^^^TEST^^^
7
-----
64
$$$TEST$$$

^^^TEST^^^
9
-----
36
$$$TEST$$$

^^^TEST^^^
32
-----
840
$$$TEST$$$

^^^TEST^^^
15
-----
144
$$$TEST$$$

*/
