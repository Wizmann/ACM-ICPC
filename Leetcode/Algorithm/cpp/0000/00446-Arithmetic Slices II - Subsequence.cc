typedef long long llint;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<unordered_map<llint, int> > dp(n);
        unordered_set<int> st(A.begin(), A.end());
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                llint delta = 1LL * A[i] - A[j];
                ans += dp[j][delta];
                if (st.count(A[i] + delta)) {
                    dp[i][delta] += dp[j][delta] + 1;
                }
            }
        }
        
        return ans;
    }
};
