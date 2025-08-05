const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int> > q;
        n = rooms.size();
        if (n == 0) {
            return;
        }
        m = rooms[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            int dis = rooms[cur.first][cur.second];
            for (int i = 0; i < 4; i++) {
                int ny = cur.first + my[i];
                int nx = cur.second + mx[i];
                
                if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                    if (dis + 1 < rooms[ny][nx]) {
                        rooms[ny][nx] = dis + 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }
private:
    int n, m;
};
