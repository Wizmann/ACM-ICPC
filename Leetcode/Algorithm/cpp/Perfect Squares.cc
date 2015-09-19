class Solution {
typedef long long llint;
public:
    int numSquares(int n) {
        vector<int> dp = {0, 1, 2, 3, 1};
        llint square_root = 3;
        for (int i = 5; i <= n; i++) {
            if (i == square_root * square_root) {
                dp.push_back(1);
                square_root++;
                continue;
            }
            int mini = numeric_limits<int>::max();
            for (int j = 1; j * j <= i; j++) {
                mini = min(mini, dp[j * j] + dp[i - j * j]);
            }
            dp.push_back(mini);
        }
        return dp[n];
    }
};
