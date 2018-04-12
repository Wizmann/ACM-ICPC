const int INF = 0x3f3f3f3f;

class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        n = A.size();
        dp = vector<int>(n, INF);
        pre = vector<int>(n, -1);
        if (A[n - 1] == -1) {
            return {};
        }
        dp[n - 1] = A[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            if (A[i] == -1) {
                continue;
            }
            for (int j = 1; j <= B && i + j < n; j++) {
                if (dp[i + j] == INF) {
                    continue;
                }
                if (dp[i] > dp[i + j] + A[i]) {
                    dp[i] = dp[i + j] + A[i];
                    pre[i] = i + j;
                }
            }
        }
        
        if (dp[0] == INF) {
            return {};
        }
        
        vector<int> res;
        for (int i = 0; i != n - 1; /* pass */) {
            res.push_back(i + 1);
            i = pre[i];
        }
        res.push_back(n);      
        return res;
    }
private:
    int n;
    vector<int> dp;
    vector<int> pre;
};
