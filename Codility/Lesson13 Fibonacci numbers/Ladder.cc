// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

const int SIZE = 55555;

vector<int> solution(vector<int> &A, vector<int> &B) {
    int n = A.size();
    const int mod = (1 << 30) - 1;
    vector<int> dp(SIZE, 0);
    vector<int> res(n, 0);
    dp[0] = dp[1] = 1;
    
    for (int i = 2; i < SIZE; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) & mod;
    }
    
    for (int i = 0; i < n; i++) {
        res[i] = dp[A[i]] & ((1 << B[i]) - 1);
    }
    
    return res;
}
