const int INF = 0x3f3f3f3f;
const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest_) {
        forest = forest_;
        n = forest.size();
        m = forest[0].size();
        
       
        trees.push_back({0, 0});
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (forest[i][j] > 1) {
                    trees.push_back({i, j});
                }
            }
        }

        sort(trees.begin() + 1, trees.end(), [&](const pair<int, int>& pa, const pair<int, int>& pb) {
            return forest[pa.first][pa.second] < forest[pb.first][pb.second];
        });
        
        int res = 0;
        int k = trees.size();
        
        for (int i = 0; i + 1 < k; i++) {
            int dis = bfs(trees[i].first, trees[i].second, trees[i + 1].first, trees[i + 1].second);
            // cout << trees[i].first << ' ' << trees[i].second << ' ' << trees[i + 1].first << ' ' << trees[i + 1].second << ' ' << dis << endl;
            if (dis == INF) {
                res = -1;
                break;
            }
            res += dis;
        }
        return res;
    }
private:
    int pointId(pair<int, int> p) {
        return pointId(p.first, p.second);
    }
    
    int pointId(int y, int x) {
        return y * m + x;
    }
    
    int pointPairId(int a, int b) {
        return a * 2479 + b;
    }
    
    int bfs(int y0, int x0, int y1, int x1) {
        queue<pair<char, char> > q;
        q.push({y0, x0});
        
        int ida = pointId(y0, x0);
        int ide = pointId(y1, x1);
        
        mp.clear();

        mp[ida] = 0;
        
        if (y0 == y1 && x0 == x1) {
            return 0;
        }
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int y = cur.first;
            int x = cur.second;
            
            int idb = pointId(y, x);
            int step = mp[idb];
            
            for (int i = 0; i < 4; i++) {
                int ny = y + my[i];
                int nx = x + mx[i];
                int idc = pointId(ny, nx);
                
                if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                    if (forest[ny][nx] != 0 && mp.count(idc) == 0) {
                        mp[idc] = step + 1;
                        if (ny == y1 && nx == x1) {
                            return step + 1;
                        }
                        q.push({ny, nx});
                    }
                }
            }
        }
        return INF;
    }
private:
    int n, m;
    vector<pair<char, char> > trees;
    vector<vector<int> > forest;
    unordered_map<short, short > mp;
};
