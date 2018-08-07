const int INF = 0x3f3f3f3f;

struct Edge {
    int dest, cost, id;
};

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        g = vector<vector<Edge> >(N);
        
        int idx = 0;
        maxi = vector<int>(edges.size(), 0);
        for (const auto& edge: edges) {
            int a = edge[0];
            int b = edge[1];
            int c = edge[2];
            g[a].push_back({b, c + 1, idx});
            g[b].push_back({a, c + 1, idx});
            maxi[idx] += c;
            idx++;
        }
        
        spfa(N, 0);
        points = vector<int>(edges.size(), 0);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (dis[i] >= INF) {
                continue;
            }
            int rem = M - dis[i];
            if (rem < 0) {
                continue;
            }
            ans++;
            for (const auto& edge: g[i]) {
                idx = edge.id;
                points[idx] += rem;
            }
        }
        
        for (int i = 0; i < edges.size(); i++) {
            ans += min(points[i], maxi[i]);
        }
        return ans;
    }
private:
    void spfa(int n, int st) {
        dis = vector<int>(n, INF);
        visited = vector<bool>(n, false);
        
        queue<int> q;
        q.push(st);
        dis[st] = 0;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = false;
            
            for (const auto& edge: g[cur]) {
                if (dis[cur] + edge.cost < dis[edge.dest]) {
                    dis[edge.dest] = dis[cur] + edge.cost;
                    if (!visited[edge.dest]) {
                        q.push(edge.dest);
                        visited[edge.dest] = true;
                    }
                }
            }
        }
    }
private:
    vector<vector<Edge> > g; 
    vector<int> dis;
    vector<bool> visited;
    vector<int> points;
    vector<int> maxi;
};
