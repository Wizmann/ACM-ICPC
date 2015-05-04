class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        int n = A.size();
        radix_sort(A, n);
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
private:
    void radix_sort(vector<int>& A, int n) {
        for (int i = 0; i < n; i++) {
            while (true) {
                if (A[i] <= 0 || A[i] > n) {
                    break;
                }
                if (A[A[i] - 1] == A[i]) {
                    break;
                }
                swap(A[A[i] - 1], A[i]);
            }
        }
    }
};
