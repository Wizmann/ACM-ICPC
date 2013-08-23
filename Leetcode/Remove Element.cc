class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int ptr = n - 1;
        int i = 0;
        while (i <= ptr) {
            if (A[ptr] == elem) {
                ptr--;
            } else if (A[i] == elem) {
                swap(A[i], A[ptr]);
            } else {
                i++;
            }
        }
        return i;
    }
};
