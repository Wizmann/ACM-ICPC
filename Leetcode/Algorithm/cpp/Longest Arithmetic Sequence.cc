class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        n = A.size();
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                int delta = A[i] - A[j];
                
                dp[{i, delta}] = max(dp[{i, delta}], dp[{j, delta}] + 1);
                ans = max(ans, dp[{i, delta}]);
            }
        }
        return ans + 1;
    }
private:
    int n;
    map<pair<int, int>, int> dp;
};
