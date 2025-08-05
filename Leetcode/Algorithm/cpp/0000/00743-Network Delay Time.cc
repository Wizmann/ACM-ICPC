const int SIZE = 111;
const int INF = 0x3f3f3f3f;

struct Node {
    int dest;
    int cost;
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        memset(dis, INF, sizeof(dis));
        memset(visit, false, sizeof(visit));
        
        for (const auto& time: times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            g[u].push_back({v, w});
        }
        
        dis[k] = 0;
        queue<int> q;
        q.push(k);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visit[cur] = false;
            
            for (const auto& node: g[cur]) {
                int next = node.dest;
                int cost = node.cost;
                
                if (dis[cur] + cost < dis[next]) {
                    dis[next] = dis[cur] + cost;
                    if (!visit[next]) {
                        q.push(next);
                    }
                }
            }
        }
        
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, dis[i]);
        }
        
        if (res == INF) {
            return -1;
        }
        return res;        
    }
private:
    int dis[SIZE];
    bool visit[SIZE];
    vector<Node> g[SIZE];
};
