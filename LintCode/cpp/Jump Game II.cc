class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        int n = A.size();
        vector<int> DP(n, numeric_limits<int>::max());
        DP[0] = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int l = maxi + 1;
            int r = i + A[i];
            
            for (int j = l; j <= min(n - 1, r); j++) {
                DP[j] = min(DP[j], DP[i] + 1);
            }
            maxi = max(maxi, r);
        }
        return DP[n - 1];
    }
};
