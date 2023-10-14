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

const int MAXN = 1234;
const int MAXT = 12345;

const int MOD = 998244353;

int n, x;
vector<int> ts;
int dp[MAXN][MAXT];
int delta[MAXT];
int cp;

int mypow(llint a, llint b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int solve() {
    memset(dp, 0, sizeof(dp));
    memset(delta, 0, sizeof(delta));

    for (int id = 0; id < n; id++) {
        dp[id][0] = (1LL * dp[id][0] + cp) % MOD;
    }
    int res = 0;

    for (int t = 0; t <= x; t++) {
        for (int id = 0; id < n; id++) {
            int p = (1LL * dp[id][t] + delta[t]) % MOD;
            if (p == 0) {
                continue;
            }

            if (t + ts[id] > x) {
                if (id == 0) {
                    res = (res + p) % MOD;
                }
                continue;
            }

            int nxt_t = t + ts[id];
            int nxt_p = (1LL * p * cp) % MOD;
            delta[nxt_t] = (1LL * delta[nxt_t] + nxt_p) % MOD;
        }
    }
    return res;
}

int main() {
    input(n, x);

    cp = mypow(n, MOD - 2);

    ts.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ts[i]);
    }

    print(solve());

    return 0;
}

/*

^^^TEST^^^
1 3
3
-----
1
$$$TEST$$$

^^^TEST^^^
2 6
3 3
-----
499122177
$$$TEST$$$

^^^TEST^^^
3 6
3 5 6
-----
369720131
$$$TEST$$$

^^^TEST^^^
5 0
1 2 1 2 1
-----
598946612
$$$TEST$$$

^^^TEST^^^
5 10000
1 2 3 4 5
-----
586965467
$$$TEST$$$

*/
