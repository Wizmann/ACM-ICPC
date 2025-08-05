const int INF = 0x3f3f3f3f;
const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

struct MyPoint {
    int x, y;
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        if (n == 0) {
            return res;
        }
        m = matrix[0].size();
        if (m == 0) {
            return res;
        }
        
        res = vector<vector<int> >(n, vector<int>(m, INF));
        
        queue<MyPoint> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({j, i});
                }
            }
        }
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int ny = p.y + my[i];
                int nx = p.x + mx[i];
                
                if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                    if (res[ny][nx] > res[p.y][p.x] + 1) {
                        res[ny][nx] = res[p.y][p.x] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return res;
    }
private:
    int n, m;
    vector<vector<int> > res;
};
