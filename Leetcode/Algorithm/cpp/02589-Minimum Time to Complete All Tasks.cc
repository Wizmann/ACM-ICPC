const int N = 2222;

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        vector<bool> visited(N, false);

        sort(tasks.begin(), tasks.end(), [](const auto& t1, const auto& t2) {
            return t1[1] < t2[1];
        });

        for (auto& task : tasks) {
            int l = task[0];
            int r = task[1];
            int c = task[2];

            for (int i = l; i <= r; i++) {
                if (visited[i]) {
                    c--;
                }
                if (c == 0) {
                    break;
                }
            }
            for (int i = r; i >= l && c > 0; i--) {
                if (!visited[i]) {
                    visited[i] = true;
                    c--;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                res++;
            }
        }
        return res;
    }
};
