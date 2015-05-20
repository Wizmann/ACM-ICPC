class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        sort(S.begin(), S.end());
        
        int n = S.size();
        int ans = 0;
        
        for (int i = 0; i + 2 < n; i++) {
            int r = i + 2;
            
            for (int j = i + 1; j < n; j++) {
                while (r < n && S[r] < S[i] + S[j]) {
                    r++;
                }
                if (r - 1 > j) {
                    ans += (r - j - 1);
                }
            }
        }
        return ans;   
    }
};
