const int SIZE = 55;

inline int lowbit(int x) {
    return x & (-x);
}

int bit_count(int u) {
    int res = 0;
    while (u) {
        res++;
        u -= lowbit(u);
    }
    return res;
}

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        dp[0][0][0] = 0;
        
        for (int i = 0; i < n; i++) {
            for (int a0 = 0; a0 < n; a0++) {
            for (int b0 = 0; b0 < n; b0++) {
                vector<int> As(n, -1);
                vector<int> Bs(n, -1);
                
                if (dp[i][a0][b0] == -1) {
                    continue;
                }
                
                int u = 0;
                for (int a1 = a0; a1 < n; a1++) {
                    if (grid[i][a1] == -1) {
                        break;
                    }
                    if (grid[i][a1] == 1) {
                        u |= 1 << a1;
                    }
                    As[a1] = u;
                }
                
                int v = 0;
                for (int b1 = b0; b1 < n; b1++) {
                    if (grid[i][b1] == -1) {
                        break;
                    }
                    if (grid[i][b1] == 1) {
                        v |= 1 << b1;
                    }
                    Bs[b1] = v;
                }
        
                for (int a1 = a0; a1 < n; a1++) {
                for (int b1 = b0; b1 < n; b1++) {
                    if (As[a1] == -1 || Bs[b1] == -1) {
                        continue;
                    }
                    int x = bit_count(As[a1] | Bs[b1]);
                    int y = dp[i][a0][b0];
                    dp[i + 1][a1][b1] = max(dp[i + 1][a1][b1], x + y);
                }
                }
            }
            }
        }
        int res = dp[n][n - 1][n - 1];
        if (res == -1) {
            return 0;
        } else {
            return res;
        }
    }
private:
    int n;
    int dp[SIZE][SIZE][SIZE];
};
