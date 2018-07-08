#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

const int N = 111;
const int M = 12345;

int n, m, k;
int board[N][M];
int dis[N][M];
int dp[2][M];
pair<int, int> pre[M];

int main() {
    while (input(n >> m >> k) && n + m + k) {
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &board[i][j]);
            }
        }

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &dis[i][j]);
            }
        }

        memset(dp, 0, sizeof(dp));

        int p = 0;
        int q = 0;
        for (int i = 0; i < n + 1; i++) {
            q = p ^ 1;

            memset(dp[q], 0, sizeof(dp[q]));

            deque<int> dq;

            dq.clear();
            memset(pre, 0, sizeof(pre));
            pre[0] = pair<int, int>(0, 0);
            pre[1] = {board[i][0], dis[i][0]};
            for (int j = 2; j <= m; j++) {
                pre[j].first = pre[j - 1].first + board[i][j - 1];
                pre[j].second = pre[j - 1].second + dis[i][j - 1];
            }

            for (int j = 0; j <= m; j++) {
                dp[q][j] = max(dp[q][j], dp[p][j]);

                while (!dq.empty() && pre[j].second - pre[dq.front()].second > k) {
                    dq.pop_front();
                }

                if (!dq.empty()) {
                    dp[q][j] = max(dp[q][j], dp[p][dq.front()] + pre[j].first - pre[dq.front()].first);
                }

                while (!dq.empty() && 
                        dp[p][dq.back()] + pre[j].first - pre[dq.back()].first < dp[p][j]) {
                    dq.pop_back();
                }
                dq.push_back(j);
            }

            dq.clear();
            memset(pre, 0, sizeof(pre));
            pre[m] = pair<int, int>(0, 0);
            pre[m - 1] = {board[i][m - 1], dis[i][m - 1]};
            for (int j = m - 2; j >= 0; j--) {
                pre[j].first = pre[j + 1].first + board[i][j];
                pre[j].second = pre[j + 1].second + dis[i][j];
            }

            for (int j = m; j >= 0; j--) {
                dp[q][j] = max(dp[q][j], dp[p][j]);

                while (!dq.empty() && pre[j].second - pre[dq.front()].second > k) {
                    dq.pop_front();
                }

                if (!dq.empty()) {
                    dp[q][j] = max(dp[q][j], dp[p][dq.front()] + pre[j].first - pre[dq.front()].first);
                }

                while (!dq.empty() && 
                        dp[p][dq.back()] + pre[j].first - pre[dq.back()].first < dp[p][j]) {
                    dq.pop_back();
                }
                dq.push_back(j);
            }

            /*
            for (int j = 0; j <= m; j++) {
                printf("%d ", dp[q][j]);
            }
            puts("");
            */
            p = q;
        }

        int ans = 0;
        for (int i = 0; i <= m; i++) {
            ans = max(ans, dp[p][i]);
        }
        print(ans);
    }
    return 0;
}
