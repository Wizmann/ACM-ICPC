class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    Solution() {
        init();
    }
    
    int numTrees(int n) {
        return dp[n];    
    }
private:
    void init() {
        dp.resize(2333);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < 2333; i++) {
            for (int j = 0; j <= i - 1; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
    }
private:
    vector<int> dp;
};
