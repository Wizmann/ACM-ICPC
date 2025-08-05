const int SIZE = 51234;
char dp[SIZE];

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        std::sort(rewardValues.begin(), rewardValues.end());
        auto last = std::unique(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(last, rewardValues.end());

        int maxi = rewardValues.back();
        memset(dp, 0, sizeof(dp));
        
        dp[0] = true;
        for (auto value : rewardValues) {
            for (int i = 0; i < min(value, maxi - value) && i + value < maxi; i++) {
                if (dp[i]) {
                    dp[i + value] = true;
                }
            }
        }

        for (int i = maxi - 1; i >= 0; i--) {
            if (dp[i]) {
                return i + maxi;
            }
        }
        return -1;
    }
};
