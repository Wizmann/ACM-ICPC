#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

const int N = 3333;

vector<int> g[N];
int n, m;
int dp[N][N];

void bfs(int st) {
    queue<int> q;
    q.push(st);
    dp[st][st] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next: g[cur]) {
            if (next == cur) {
                continue;
            }
            if (dp[st][next] > dp[st][cur] + 1) {
                dp[st][next] = dp[st][cur] + 1;
                q.push(next);
            }
        }
    }
}


int main() {
    input(n >> m);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        bfs(i);
    }
    
    int s1, t1, l1;
    int s2, t2, l2;
    input(s1 >> t1 >> l1);
    input(s2 >> t2 >> l2);

    int maxi = -INF;

    if (dp[s1][t1] <= l1 && dp[s2][t2] <= l2) {
        maxi = m - (dp[s1][t1] + dp[s2][t2]);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                {
                    int d1 = min(
                            dp[s1][i] + dp[i][j] + dp[j][t1],
                            dp[s1][j] + dp[j][i] + dp[i][t1]);

                    int d2 = min(
                            dp[s2][i] + dp[i][j] + dp[j][t2],
                            dp[s2][j] + dp[j][i] + dp[i][t2]);
                    assert(dp[i][j] == dp[j][i]);
                    if (d1 > l1 || d2 > l2) {
                        continue;
                    }
                    maxi = max(maxi, m - d1 - d2 + dp[i][j]);
                }
            }
        }
    }

    if (maxi <= -INF) {
        maxi = -1;
    }
    print(maxi);

    return 0;
}
