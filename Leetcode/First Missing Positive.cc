class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; i++) {
            A[i]--;
        }
        
        for (int i = 0; i < n; i++) {
            while (A[i] != i && A[i] >= 0 && A[i] < n && A[i] != A[A[i]]) {
                assert(A[i] >= 0);
                swap(A[i], A[A[i]]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
