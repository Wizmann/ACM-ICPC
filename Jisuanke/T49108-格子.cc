#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
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

llint mypow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return res;
}

int main() {
    int n, m;
    input(n, m);

    assert(mypow(2, 10) == 1024);
    
    llint tot = 0;
    llint a1 = 1;
    llint b1 = 1;

    llint a2 = 1;
    llint b2 = 1;

    for (int i = 1; i <= min(m, n); i++) {
        a1 = a1 * mypow(i, MOD - 2) % MOD;
        b1 = b1 * (n - i + 1) % MOD;

        if (i > 1) {
            b2 = b2 * (m - i + 1) % MOD;
            a2 = a2 * mypow(i - 1, MOD - 2) % MOD;
        }
        llint c = a2 * b2 % MOD;


        llint cur = (a1 * b1) % MOD * c % MOD;
        // print(cur, a1 * b1 % MOD, c);
        tot = (tot + cur) % MOD;
    }
    printf("%lld", tot);

    return 0;
}

/*
^^^TEST^^^
3 2
----
6
$$$TEST$$$

^^^TEST^^^
3 3
----
10
$$$TEST$$$

^^^TEST^^^
3 4
----
15
$$$TEST$$$

^^^TEST^^^
4 3
----
20
$$$TEST$$$

^^^TEST^^^
4 6
----
84
$$$TEST$$$
*/
