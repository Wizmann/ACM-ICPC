const int SIZE = 55;

class Solution {
public:
    int maxA(int N) {
        vector<int> dp(SIZE, 0);
        
        for (int i = 1; i < SIZE; i++) {
            dp[i] = max(dp[i], dp[i - 1] + 1); // add A
            if (i - 3 >= 0) {
                int cnt = dp[i - 3];
                for (int j = 0; j + i < SIZE; j++) {
                    dp[i + j] = max(dp[i + j], cnt * (j + 2));
                }
            }
            // cout << dp[i] << endl;
        }
        
        return dp[N];
    }
};
