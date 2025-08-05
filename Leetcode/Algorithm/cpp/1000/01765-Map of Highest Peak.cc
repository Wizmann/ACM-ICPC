const int INF = 0x3f3f3f3f;

const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, -1, 0, 1};

struct Point {
    int y, x;
};

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<Point> q;

        const int n = isWater.size();
        const int m = isWater[0].size();

        vector<vector<int> > res(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int ny = cur.y + my[i];
                int nx = cur.x + mx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                    continue;
                }

                if (res[ny][nx] == -1) {
                    res[ny][nx] = res[cur.y][cur.x] + 1;
                    q.push({ny, nx});
                }
            }
        }
        return res;
    }
};
