#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 55;
const int MAXBIT = 66;
const int INF = 0x3f3f3f3f;

vector<int> g[N];
char dp[MAXBIT][N][N];

int main() {
    int n, m;
    input(n >> m);

    memset(dp, 0, sizeof(dp));

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        dp[0][a][b] = 1;
    }

    for (int i = 1; i < MAXBIT; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= n; l++) {
                    dp[i][k][l] |= dp[i - 1][k][j] & dp[i - 1][j][l];
                }
            }
        }
    }

    vector<int> dis(n + 1, INF);
    dis[1] = 0;

    for (int i = MAXBIT - 1; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (dp[i][j][k]) {
                    dis[k] = min(dis[k], dis[j] + 1);
                }
            }
        }
    }

    print(dis[n]);

    return 0;
}
