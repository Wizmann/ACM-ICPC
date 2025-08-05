const int INF = 0x3f3f3f3f;

struct Point {
    int y, x;
};

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        dis = vector<vector<int> >(n);
        
        remy = vector<set<int> >(n);
        remx = vector<set<int> >(m);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                remy[i].insert(j);
            }
        }
        
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                remx[j].insert(i);
            }
        }
        
        for (int i = 0; i < n; i++) {
            dis[i] = vector<int>(m, INF);

        }
        
        dis[0][0] = 0;
        
        queue<Point> q;
        q.push({0, 0});
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            int y = cur.y;
            int x = cur.x;
            
            if (dis[y][x] >= dis[n - 1][m - 1]) {
                continue;
            }

            for (auto iter = remy[y].lower_bound(x + 1); 
                 iter != remy[y].end() && *iter <= min(m - 1, x + grid[y][x]); 
                 /* pass */) {
                int ny = y;
                int nx = *iter;
                if (dis[ny][nx] != INF) {
                    ++iter;
                    continue;
                }
                dis[ny][nx] = dis[y][x] + 1;
                iter = remy[ny].erase(iter);
                q.push({ny, nx});
            }
            
            for (auto iter = remx[x].lower_bound(y + 1);
                 iter != remx[x].end() && *iter <= min(n - 1, y + grid[y][x]);
                 /* pass */) {
                int ny = *iter;
                int nx = x;
                if (dis[ny][nx] != INF) {
                    ++iter;
                    continue;
                }
                dis[ny][nx] = dis[y][x] + 1;
                iter = remx[nx].erase(iter);
                q.push({ny, nx});
            }
        }
        int res = dis[n - 1][m - 1];
        if (res >= INF) {
            return -1;
        }
        return res + 1;
    }
private:
    vector<vector<int> > dis;
    vector<set<int> > remx, remy;
};
