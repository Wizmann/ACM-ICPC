#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    const int n = A.size();

    int res = 0;    
    for (int i = 0; i < n; i++) {
        int k = i + 2;
        for (int j = i + 1; j < n; j++) {
            int u = A[i] + A[j];
            while (k < n && A[k] < u) {
                k++;
            }
            res += k - j - 1;
        }
    }
    return res;
}
