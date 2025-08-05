class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A_) {
        A = A_;
        int ans = 0;
        n = A.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, dfs(j + 1, A[j], A[i] + A[j], 2));
            }
        }
        return ans < 2? 0: ans;
    }
private:
    int dfs(int cur, int pre, int val, int cnt) {
        if (cur == n) {
            return cnt;
        }
        int idx = distance(A.begin(), lower_bound(A.begin() + cur, A.end(), val));
        if (idx == n || A[idx] != val) {
            return dfs(n, -1, -1, cnt);
        }
        return dfs(idx + 1, A[idx], A[idx] + pre, cnt + 1);
    }
private:
    int n;
    vector<int> A;
};
