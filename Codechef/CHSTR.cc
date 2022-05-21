// #string
// #z-algorithm
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
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long llint;
typedef unsigned long long ullint;

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

const int SIZE = 5005;
const int MOD = 1000000000 + 7;
const int ALPHA = 29;
const llint STRHASH = 0xdeadbeefdeadbeef;

llint mypow(llint a, llint b, llint c) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % c;
        }
        a = (a * a) % c;
        b >>= 1;
    }
    return res;
}

llint tot[SIZE];
llint pre[SIZE];
llint inv[SIZE];


void init() {
    for (int i = 0; i < SIZE; i++) {
        inv[i] = mypow(i, MOD - 2, MOD);
    }
    assert(1000LL * inv[1000] % MOD == 1);
}

vector<int> z_function(const char* s, int n) {
    vector<int> z(n, 0);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i] += 1;
            }
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void solve(const string& s) {
    const int n = s.size();
    memset(tot, 0, sizeof(tot));

    for (int i = 0; i < n; i++) {
        vector<int> z = z_function(s.c_str() + i, n - i);
        memset(pre, 0, sizeof(pre));
        for (auto num : z) {
            pre[0]++;
            pre[num + 1]--;
        }

        int m = z.size();
        for (int j = 1; j <= m; j++) {
            pre[j] += pre[j - 1];
            tot[pre[j] + 1]++;
        }
    }

    llint u = 0;
    for (int i = SIZE - 1; i >= 1; i--) {
        tot[i] -= u;
        u += tot[i];
    }

    /*
    for (int i = 0; i <= n; i++) {
        printf("%lld ", tot[i]);
    }
    puts("");
    */

    for (int i = 1; i < SIZE; i++) {
        llint u = tot[i];
        llint v = 1;
        if (u == 0) {
            continue;
        }
        for (int j = i - 1; j > 0; j--) {
            llint step = i - j;
            v = (v * (i - step + 1) % MOD) * inv[step] % MOD;
            // print(i, j, v);
            tot[j] += (v * u) % MOD;
            tot[j] %= MOD;
        }
    }
}

char buffer[SIZE];

int main() {
    int T;
    input(T);

    init();

    while (T--) {
        int n, q;
        scanf("%d%d", &n, &q);
        scanf("%s", buffer);
        string s(buffer);

        solve(s);

        int a;
        while (q--) {
            scanf("%d", &a);
            if (a >= SIZE) {
                puts("0");
            } else {
                printf("%lld\n", tot[a]);
            }
        }
    }

    return 0;
}

/*
^^^TEST^^^
1
10 10
babaaaaaba
1
2
3
4
5
6
7
8
9
10
-------
55
39
42
36
21
7
1
0
0
0
$$$TEST$$$




^^^TEST^^^
1
5 4
ababa
2
1
3
4
-----
7
15
1
0
$$$TEST$$$

*/
