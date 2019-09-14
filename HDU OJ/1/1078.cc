#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define FOR(i, n) for (int i = 0; i < n; i++)
#define RFOR(i, n) for (int i = n - 1; i >= 0; i--)

typedef long long llint;

const int MOD = 1000000000 + 7;
const int INF = 0x3f3f3f3f;
const int N = 111;

int dp[N][N];
int board[N][N];

int n, m;

int main() {
    while (scanf("%d%d", &n, &m) != EOF && n + m >= 0) {
        FOR (i, n) {
            FOR (j, n) {
                scanf("%d", &board[i][j]);
            }
        }
        memset(dp, 0, sizeof(dp));

        dp[0][0] = board[0][0];
        queue<pair<int, int> > q;
        set<pair<int, int> > inq;
        q.push({0, 0});
        inq.insert({0, 0});

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int y = cur.first;
            int x = cur.second;
            inq.erase(inq.find({y, x}));

            FOR (i, n) {
                if (abs(i - y) > m) {
                    continue;
                }
                if (board[i][x] > board[y][x]) {
                    if (dp[i][x] < dp[y][x] + board[i][x]) {
                        dp[i][x] = dp[y][x] + board[i][x];
                        if (inq.count({i, x}) == 0) {
                            q.push({i, x});
                            inq.insert({i, x});
                        }
                    }
                }
            }

            FOR (j, n) {
                if (abs(j - x) > m) {
                    continue;
                }
                if (board[y][j] > board[y][x]) {
                    if (dp[y][j] < dp[y][x] + board[y][j]) {
                        dp[y][j] = dp[y][x] + board[y][j];
                        if (inq.count({y, j}) == 0) {
                            q.push({y, j});
                            inq.insert({y, j});
                        }
                    }
                }
            }
        }

        int ans = 0;
        FOR (i, n) {
            FOR (j, n) {
                ans = max(ans, dp[i][j]);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
