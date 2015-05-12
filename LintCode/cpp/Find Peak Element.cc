class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int n = A.size();
        int l = 0;
        int r = n - 1;
        
        while (l <= r) {
            if (detect(A, l)) {
                return l;
            }
            if (detect(A, r)) {
                return r;
            }
            int m = (l + r) >> 1;
            if (detect(A, m)) {
                return m;
            }
            if (A[m] > A[m + 1]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
private:
    bool detect(vector<int>& A, int pos) {
        int a = pos - 1;
        int b = pos + 1;
        bool flag = true;
        if (a >= 0 && A[a] > A[pos]) {
            return false;
        }
        if (b < A.size() && A[b] > A[pos]) {
            return false;
        }
        return true;
    }
};


