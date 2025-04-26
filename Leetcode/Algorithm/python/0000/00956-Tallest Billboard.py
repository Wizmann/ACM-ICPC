const int N = 5555;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        vector<int> dp[2];
        dp[0] = vector<int>(N, -1);
        dp[1] = vector<int>(N, -1);
        dp[0][0] = 0;
        int p = 0;
        for (auto rod: rods) {
            int q = p ^ 1;
            dp[q] = dp[p];
            for (int i = N - 1; i >= 0; i--) {
                if (dp[p][i] >= 0) {
                    dp[q][abs(i - rod)] = max(dp[q][(abs(i - rod))], dp[p][i] + min(i, rod));
                    dp[q][i + rod] = max(dp[q][i + rod], dp[p][i]);
                }
            }
            p = q;
        }
        return dp[p][0];
    }
};
