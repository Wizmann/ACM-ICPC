class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int n = A.size();
        int m = B.size();
        int i = 0;
        int j = 0;
        
        for (i = 0, j = 0; i < n && j < m; /* pass */) {
            if (A[i] == B[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        
        return j == m;
    }
};

