const int INF = 0x3f3f3f3f;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int> > g(n);
        for (int i = 0; i < n; i++) {
            g[i] = vector<int>(n, INF);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; i + j < n; j++) {
                g[i][i + j] = j;
            }
        }

        vector<int> res;
        for (const auto& q : queries) {
            int a = q[0];
            int b = q[1];

            if (g[a][b] > 1) {
                g[a][b] = 1;

                for (int i = 0; i < n; i++) {
                    g[i][b] = min(g[i][b], g[i][a] + 1);
                }
                for (int i = 0; i < n; i++) {
                    g[i][n - 1] = min(g[i][n - 1], g[i][b] + g[b][n - 1]);
                }
            }
            res.push_back(g[0][n - 1]);
        }
        return res;
    }
};
