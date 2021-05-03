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

const llint MOD = 998244353;

llint powmod(llint a, llint b, llint mod) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        b /= 2;
        a = (a * a) % mod;
    }
    return res;
}


llint plusmod(llint a, llint delta, llint mod) {
    a = (a + delta) % mod;
    a = (a + mod) % mod;
    return a;
}

int main() {
    int T;
    input(T);

    int m, p, q;
    while (T--) {
        scanf("%d%d%d", &m, &p, &q);

        llint r1 = 100LL * m - p;
        llint r2 = p;
        assert(r1 >= 0);

        llint delta1 = r1 * q;
        llint delta2 = r2 * 100;

        delta1 = plusmod(delta2 * m, -delta1, MOD);

        llint delta = (delta1 % MOD) * powmod(delta2, MOD - 2, MOD) % MOD;

        printf("%lld\n", delta);
    }

    return 0;
}

/*

^^^TEST^^^
2
4 100 100
1 50 50
-----
1
499122177
$$$TEST$$$

*/
