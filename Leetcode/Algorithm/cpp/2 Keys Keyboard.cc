const int INF = 0x3f3f3f3f;
const int SIZE = 1111;

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(SIZE, INF);
        dp[1] = 0;
        for (int i = 1; i < SIZE; i++) {
            for (int j = 2; i * j < SIZE; j++) {
                dp[i * j] = min(dp[i * j], dp[i] + j);
            }
        }
        return dp[n];
    }
};
