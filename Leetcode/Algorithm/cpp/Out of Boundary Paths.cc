const int SIZE = 55;
const int MOD = 1000000000 + 7;
int dp[2][SIZE][SIZE];

const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

class Solution {
public:
    int findPaths(int n, int m, int N, int y, int x) {
        memset(dp, 0, sizeof(dp));
        
        dp[0][y][x] = 1;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int cur = i % 2;
            int next = cur ^ 1;
            
            memset(dp[next], 0, sizeof(dp[next]));
            
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if (dp[cur][j][k] == 0) {
                        continue;
                    }
                    for (int l = 0; l < 4; l++) {
                        int ny = j + my[l];
                        int nx = k + mx[l];
                        
                        if (ny >= n || ny < 0 || nx >= m || nx < 0) {
                            ans = (ans + dp[cur][j][k]) % MOD;
                        } else {
                            dp[next][ny][nx] = (dp[next][ny][nx] + dp[cur][j][k]) % MOD;
                        }
                    }
                }
            }
        }
        return ans % MOD;
    }
};
