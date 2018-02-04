class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        for (int i = 0; i + 1 < n; /* pass */) {
            if (A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
                i += 2;
            } else {
                i++;
            }
        }
        
        for (int i = 0; i + 1 < n; i++) {
            if (A[i] > A[i + 1]) {
                return false;
            }
        }
        
        return true;
    }
};
