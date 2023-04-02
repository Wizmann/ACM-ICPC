const int INF = 0x3f3f3f3f;
const int N = 1111;

struct Edge {
    int dest, id;
};

vector<Edge> g[N];
vector<int> dis;

int dijkstra(int disabled, int st, int end) {
    dis = vector<int>(N, INF);
    dis[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        int cost = cur.first;
        int p = cur.second;
        
        if (dis[p] != cost) {
            continue;
        }
        
        for (auto& e: g[p]) {
            if (e.id == disabled) {
                continue;
            }
            int dest = e.dest;
            if (dis[dest] > cost + 1) {
                dis[dest] = cost + 1;
                pq.push({cost + 1, dest});
            }
        }
    }
    if (dis[end] < INF) {
        return dis[end] + 1;
    } else {
        return INF;
    }
}

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < N; i++) {
            g[i].clear();
        }
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            g[a].push_back({b, i});
            g[b].push_back({a, i});
        }
        
        int res = INF;
        for (int i = 0; i < m; i++) {
            res = min(res, dijkstra(i, edges[i][0], edges[i][1]));
        }
        if (res == INF) {
            return -1;
        }
        return res;
    }
};
