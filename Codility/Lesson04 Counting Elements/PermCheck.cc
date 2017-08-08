// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        while (A[i] != i + 1) {
            if (A[i] > n) {
                break;
            }
            if (A[i] == A[A[i] - 1]) {
                break;
            }
            swap(A[i], A[A[i] - 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) {
            return 0;
        }
    }
    
    return 1;
}
