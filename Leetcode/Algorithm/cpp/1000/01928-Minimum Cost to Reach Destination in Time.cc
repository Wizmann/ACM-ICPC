const int INF = 0x3f3f3f3f;
const int N = 1111;

int dp[N][N];

struct Node {
    int pos, time;
};

struct Edge {
    int dest, time;
};

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        memset(dp, INF, sizeof(dp));
        int n = passingFees.size();
        
        vector<vector<Edge> > g(n);
        
        for (auto& v : edges) {
            g[v[0]].push_back({v[1], v[2]});
            g[v[1]].push_back({v[0], v[2]});
        }
        
        dp[0][0] = passingFees[0];
        
        queue<Node> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int p = cur.pos;
            int t = cur.time;
            
            if (t > maxTime) {
                continue;
            }
            
            for (auto& e : g[p]) {
                int nxt = e.dest;
                int tt = t + e.time;
                if (tt > maxTime) {
                    continue;
                }
                int cost = dp[p][t] + passingFees[nxt];
                if (dp[nxt][tt] > cost) {
                    dp[nxt][tt] = cost;
                    q.push({nxt, tt});
                }
            }
        }
        
        int res = INF;
        for (int i = 0; i <= maxTime; i++) {
            res = min(res, dp[n - 1][i]);
        }
        if (res >= INF) {
            res = -1;
        }
        return res;
    }
};
