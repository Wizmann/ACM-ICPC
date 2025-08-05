const int INF = 0x3f3f3f3f;
const int SIZE = 555;

class Solution {
public:
    int getMoneyAmount(int n) {
        memset(dp, INF, sizeof(dp));
        return dfs(1, n);
    }
private:
    int dfs(int l, int r) {
        if (l >= r) {
            return 0;
        }
        if (dp[l][r] != INF) {
            return dp[l][r];
        }
        int ans = INF;
        for (int i = l; i <= r; i++) {
            int cost = i;
            cost += max(dfs(l, i - 1), dfs(i + 1, r));
            ans = min(ans, cost);
        }
        return dp[l][r] = ans;
    }
private:
    int dp[SIZE][SIZE];
};
