int solution(vector<int> &A) {
    if (A.empty()) {
        return 0;
    }
    const int n = A.size();
    int ans = 0;
    int mini = A[0];
    
    for (int i = 1; i < n; i++) {
        ans = max(ans, A[i] - mini);
        mini = min(mini, A[i]);
    }
    return ans;
}
