class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int a = 0, b = 0;
        int ptr = 0;
        int* _A = new int[m];
        int* _B = new int[n];
        memcpy(_A, A, sizeof(int) * m);
        memcpy(_B, B, sizeof(int) * n);
        while (a < m && b < n) {
            if (_A[a] < _B[b]) {
                A[ptr++] = _A[a++];
            } else {
                A[ptr++] = _B[b++];
            }
        }
        while (a < m) {
            A[ptr++] = _A[a++];
        }
        while (b < n) {
            A[ptr++] = _B[b++];
        }
        delete [] _A;
        delete [] _B;
    }
};
