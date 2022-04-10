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

void debug() {
#ifdef __CPRUN__
    cout << "\n";
#endif
}

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

template <typename...T, typename X>
void debug(X&& x, T... args) {
#ifdef __CPRUN__
    cout << x << " "; print(args...);
#else
    (void)(x); debug(args...);
#endif
}

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int N = 123456;
const llint MOD = 1000000009LL;

llint fs[N];
llint inv[N];

llint mypow(llint a, llint b) {
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

void init() {
    fs[0] = 1;
    for (int i = 1; i < N; i++) {
        fs[i] = (fs[i - 1] * i) % MOD;
    }

    for (int i = 0; i < N; i++) {
        inv[i] = mypow(fs[i], MOD - 2);
    }
    assert(inv[0] == 1);
}

llint C(llint base, const vector<int>& ns) {
    llint res = 0;
    int p = 0;
    for (int i = 0; i <= base; i++) {
        llint u = (fs[base] * inv[base - i]) % MOD;
        u = (u * inv[i]) % MOD;

        if (p < (int)ns.size() && ns[p] == i) {
            // debug(ns[p], i, u);
            res += u;
            res %= MOD;
            p++;
        }
    }
    return res % MOD;
}

int main() {
    init();
    // assert(C(5, {3}) == 10);

    int n, m;
    while (input(n, m)) {
        vector<int> ns(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }


        int l = ns[0];
        int r = ns[0];

        for (int i = 1; i < n; i++) {
            int l1 = INF;
            l1 = min(l1, abs(l - ns[i]));
            l1 = min(l1, abs(r - ns[i]));
            if (l <= ns[i] && ns[i] <= r) {
                l1 = min(l1, (ns[i] - l) % 2);
            }

            int r1 = -INF;
            int u = l + ns[i];
            if (u > m) {
                u = m - (u - m);
            }
            r1 = max(r1, u);

            u = r + ns[i];
            if (u > m) {
                u = m - (u - m);
            }
            r1 = max(r1, u);

            debug(m - ns[i]);
            if (l <= m - ns[i] && m - ns[i] <= r) {
                if ((m - ns[i] - l) % 2 == 0) {
                    r1 = max(r1, m);
                } else {
                    r1 = max(r1, m - 1);
                }
            }
            l = min(l1, r1);
            r = max(l1, r1);
            // debug(i, l, r);
        }

        vector<int> ms;
        for (int i = l; i <= r; i += 2) {
            debug(i);
            ms.push_back(i);
        }

        printf("%lld\n", C(m, ms) % MOD);
    }

    return 0;
}


/*
^^^^TEST^^^
3 4
3 2 3
----
8
$$$TEST$$$

^^^^TEST^^^
10 10
0 1 2 3 4 5 6 7 8 9
6 10
1 3 5 2 4 6
6 18
1 3 5 2 4 6
3 7
1 4 2
3 7
1 4 6
----
512
512
131072
64
63
$$$TEST$$$

^^^^TEST^^^
3 4
3 2 3
3 4
3 2 1
3 3
3 2 3
3 10
3 2 1
3 10
3 2 7
3 10
1 3 9
-------
8
8
3
466
511
382
$$$TEST$$$

^^^TEST^^^
4 145
1 2 3 4
4 145
1 2 3 4
4 145
1 2 3 4
------
786118793
786118793
786118793
$$$TEST$$$

^^^TEST^^^
4 199
1 100 189 3
4 10
1 2 3 4
4 15
1 2 3 4
4 145
1 2 3 4
-------
88228041
512
15914
786118793
$$$TEST$$$

^^^^TEST^^^
3 20
1 3 9
7 13
1 3 9 4 0 0 1
4 13
1 0 0 9
4 13
1 0 0 3
4 13
3 0 0 3
4 13
3 13 0 2
3 3
1 1 1
-------
506464
4096
1573
793
2510
1586
4
$$$TEST$$$
*/

