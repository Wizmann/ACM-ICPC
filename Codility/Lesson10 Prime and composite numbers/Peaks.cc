// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool solve(const vector<int> &A, int k) {
    int n = A.size();
    // cout << k << endl;
    bool res = true;
    for (int i = 0; i < n; i += k) {
        bool flag = false;
        for (int j = 0; j < k; j++) {
            int p = i + j;
            if (p - 1 < 0 || p + 1 >= n) {
                continue;
            }
            int cur = A[p];

            if (A[p - 1] < cur && cur > A[p + 1]) {
                flag = true;
            }
        }
        // cout << i << ' ' << i + k << ' ' << flag << endl;
        res &= flag;
    }
    return res;
} 

int solution(vector<int> &A) {
    int n = A.size();
    if (n <= 2) {
        return 0;
    }
    int ans = 0;
    for (int i = 1; 1LL * i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        
        if (solve(A, i)) {
            ans = max(ans, n / i);
        }
        if (solve(A, n / i)) {
            ans = max(ans, i);
        }
    }
    return ans;
}
