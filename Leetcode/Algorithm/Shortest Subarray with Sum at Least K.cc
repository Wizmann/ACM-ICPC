const int INF = 0x3f3f3f3f;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        const int n = A.size();
        vector<int> B = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            B[i] = B[i - 1] + A[i - 1];
        }
        
        int res = INF;
        deque<int> dq;
        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && B[i] - B[dq.front()] >= K) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && B[i] <= B[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        if (res == INF) {
            res = -1;
        }
        return res;
    }
};
