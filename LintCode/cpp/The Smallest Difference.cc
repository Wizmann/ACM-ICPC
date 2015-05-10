class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int n = A.size();
        int m = B.size();
        int ans = INF;
        
        for (int i = 0, j = 0; i < n && j < m; /* pass */) {
            ans = min(ans, abs(A[i] - B[j]));
            if (A[i] < B[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return ans;
    }
private:
    static const int INF = numeric_limits<int>::max();
};

