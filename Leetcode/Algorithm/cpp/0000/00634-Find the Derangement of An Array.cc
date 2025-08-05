const int SIZE = 1234567;
const int MOD = 1000000000 + 7;

class Solution {
public:
    Solution() {
        dp = vector<int>(SIZE, 0);
        dp[2] = 1;
        for (int i = 3; i < SIZE; i++) {
            dp[i] = 1LL * (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
        }
    }
    int findDerangement(int n) {
        return dp[n];
    }
private:
    vector<int> dp;
};
