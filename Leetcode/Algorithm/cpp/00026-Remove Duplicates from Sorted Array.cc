class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (i && A[i] == A[i - 1]) {
                continue;
            }
            A[ptr++] = A[i];
        }
        return ptr;
    }
};
