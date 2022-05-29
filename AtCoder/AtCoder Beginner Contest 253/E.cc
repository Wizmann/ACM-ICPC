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
const int M = 5555;

llint dp[2][M];

void make_presum(int idx) {
    for (int i = 1; i < M; i++) {
        dp[idx][i] = (dp[idx][i] + dp[idx][i - 1]) % MOD;
        assert(dp[idx][i] >= 0);
    }
}

llint get_presum(int idx, int l, int r) {
    assert(l > 0);
    llint res = dp[idx][r] - dp[idx][l - 1];
    res = (res % MOD + MOD) % MOD;
    return res;
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++) {
        dp[0][i] = 1;
    }
    make_presum(0);

    int p = 0;
    for (int i = 2; i <= n; i++) {
        int q = p ^ 1;
        memset(dp[q], 0, sizeof(dp[q]));

        for (int j = 1; j <= m; j++) {
            llint cur = 0;
            if (k == 0) {
                cur = (cur + get_presum(p, 1, m)) % MOD;
            } else {
                int l = j - k;
                if (l >= 1) {
                    cur = (cur + get_presum(p, 1, l)) % MOD;
                }

                int r = j + k;
                if (r <= m) {
                    cur = (cur + get_presum(p, r, m)) % MOD;
                }
                // print(j, l, r, cur);
            }

            dp[q][j] = cur % MOD;
            assert(dp[q][j] >= 0);
        }

        make_presum(q);
        p = q;
    }

    llint res = get_presum(p, 1, m) % MOD;
    print(res);

    return 0;
}

/*

^^^TEST^^^
2 3 1
-----
6
$$$TEST$$$

^^^TEST^^^
3 3 2
-----
2
$$$TEST$$$

^^^TEST^^^
100 1000 500
-----
657064711
$$$TEST$$$

^^^TEST^^^
3 1 2
-----
0
$$$TEST$$$

^^^TEST^^^
2 3 2
-----
2
$$$TEST$$$

^^^TEST^^^
10 3 0
-----
59049
$$$TEST$$$

*/
