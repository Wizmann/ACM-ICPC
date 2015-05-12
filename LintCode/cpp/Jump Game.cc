class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        int n = A.size();
        vector<int> visit;
        visit.resize(n);
        visit[0] = 1;
        for (int i = 0; i < n; i++) {
            if (visit[i]) {
                for (int j = i + 1; j < min(n, i + A[i] + 1); j++) {
                    visit[j]++;
                }
            }
        }
        return visit[n - 1];
    }
};

