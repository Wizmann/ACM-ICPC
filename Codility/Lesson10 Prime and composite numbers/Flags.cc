// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <cmath>

bool solve(const vector<int>& peaks, int k) {
    int cnt = 0;
    int pre = -1;
    
    for (auto peak: peaks) {
        if (pre == -1) {
            cnt++;
            pre = peak;
        } else if (peak - pre >= k) {
            cnt++;
            pre = peak;
        }
    }
    
    return cnt >= k;
}

int solution(vector<int> &A) {
    vector<int> peaks;
    
    int n = A.size();
    
    for (int i = 1; i + 1 < n; i++) {
        if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
            peaks.push_back(i);
        }
    }
    
    int m = peaks.size();
    
    if (m == 0) {
        return 0;
    }
    
    int l = 1;
    int r = sqrt(n) + 1;
    
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (solve(peaks, mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    return r;
}
