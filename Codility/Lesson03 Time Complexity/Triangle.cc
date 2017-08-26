#include <algorithm>

int solution(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    for (int i = 0; i + 2 < n; i++) {
        if (1LL * A[i] + A[i + 1] > A[i + 2]) {
            return 1;
        }
    }
    return 0;
}
