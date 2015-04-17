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

const int N = 20;
const int K = 10;
const int PADDING = 19;
const int INF = 0x3f3f3f3f;

int n, k;
int dp[N + PADDING][K][(1 << K) + PADDING];
int value[K][N];

int solve() {
    for (int i = 0; i < k; i++) {
        dp[0][i][1 << i] = value[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int x = 1; x < (1 << k); x++) {
                if (!(x & (1 << j))) {
                    continue;
                }
                dp[i][j][x] = min(dp[i][j][x],
                        dp[i - 1][j][x] + value[j][i]);
                for (int y = 0; y < k; y++) {
                    if ( (x & (1 << y)) ) {
                        dp[i][j][x] = min(dp[i][j][x],
                                dp[i - 1][y][x ^ (1 << j)] + value[j][i]);
                    }
                }
                //printf("dp[%d][%d][%d] = %d\n", i, j, x, dp[i][j][x]);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < k; j++) {
            ans = min(ans, dp[n - 1][j][i]);
        }
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n >> k);
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            input(value[i][j]);
        }
    }

    memset(dp, INF, sizeof(dp));
    print(solve());
    return 0;
}

