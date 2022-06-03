struct Node {
    int dis;
    int idx;
    
    bool operator < (const Node& other) const {
        return dis > other.dis;
    }
};

const int INF = 0x3f3f3f3f;
const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        dis = vector<int>(n * m, INF);
        pq.push({0, 0});
        
        while (!pq.empty()) {
            const Node cur = pq.top();
            pq.pop();
            int y = cur.idx / m;
            int x = cur.idx % m;
            if (dis[cur.idx] <= cur.dis) {
                continue;
            }

            dis[cur.idx] = cur.dis;

            for (int i = 0; i < 4; i++) {
                int ny = y + my[i];
                int nx = x + mx[i];
                if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                    int delta = grid[ny][nx];
                    int nxt = ny * m + nx;
                    pq.push({cur.dis + delta, nxt});
                }
            }
        }
        return dis[n * m - 1];
    }
private:
    int n, m;
    priority_queue<Node> pq;
    vector<int> dis;
};
