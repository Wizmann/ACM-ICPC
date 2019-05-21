const int N = 30 * 101;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(N, 0);
        dp[0] = 1;
        int tot = accumulate(stones.begin(), stones.end(), 0);

        for (auto stone: stones) {
            for (int i = N - 1; i >= 0; i--) {
                if (dp[i] && i + stone < N) {
                    dp[i + stone] = 1;
                }
            }
        }
        
        int res = N;
        for (int i = 0; i < N; i++) {
            if (!dp[i]) {
                continue;
            }
            int a = tot - i;
            int b = i;
            res = min(res, abs(a - b));
        }
        return res;
    }
};
