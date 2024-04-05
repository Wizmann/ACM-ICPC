#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int N = 100010;

const int INF = 0x3f3f3f3f;
const llint MOD = 1000000000 + 7;

inline llint powmod(llint a, llint b, llint c) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % c;
        }
        a = a * a % c;
        b >>= 1;
    }
    return res;
}

inline llint inv(llint x) {
    return powmod(x, MOD - 2, MOD);
}

inline llint get_leaves(llint a, llint h) {
    return powmod(a, h, MOD);
}

inline llint get_nodes(llint a, llint h) {
    if (a == 1) {
        return h + 1;
    }
    return (powmod(a, h + 1, MOD) + MOD - 1) * inv(a - 1) % MOD;
}

inline llint solve(llint a, llint b, llint h) {
    if (a >= b) {
        llint bl = get_leaves(b, h);
        return (((a - b) * (get_nodes(b, h) - bl)) + a * bl) % MOD;
    } else {
        return (a * powmod(b, h, MOD)) % MOD;
    }
}

int readint() {
    int n = 0; int f = 1; char ch = getchar();
    while ('0' > ch || ch > '9') {
        if(ch == '-') f *= -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9'){
        n = (n << 1) + (n << 3) + ch - '0';
        ch = getchar();
    }
    return f * n;
}

void printllint(llint x) {
    if (x / 10) {
        printllint(x / 10);
    }
    putchar(x % 10 + '0');
}


int main() {
    int T;
    T = readint();
    while (T--) {
        llint a = readint();
        llint b = readint();
        llint h = readint();
        printllint(solve(a, b, h));
        puts("");
    }

    return 0;
}


/*
^^^TEST^^^
2
1 2 1
3 2 1
----
2
7
$$$TEST$$$

^^^TEST^^^
1
2 2 2
---
8
$$$TEST$$$

^^^TEST^^^
3
1 2 2
1 3 2
2 3 2
----
4
9
18
$$$TEST$$$

^^^TEST^^^
2
1 2 0
2 3 0
----
1
2
$$$TEST$$$
*/
