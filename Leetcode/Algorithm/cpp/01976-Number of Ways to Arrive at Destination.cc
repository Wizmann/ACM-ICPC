typedef long long llint;

const int MOD = 1000000000 + 7;
const int N = 222;
const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

struct Edge { 
    int dst; 
    int cost;
};

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        dis = vector<llint>(n, INFLL);
        dp = vector<llint>(n, 0);
        
        for (int i = 0; i < N; i++) {
            g[i].clear();
        }
        
        dis[0] = 0;
        dp[0] = 1;
        
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int t = road[2];
            
            g[u].push_back({v, t});
            g[v].push_back({u, t});
        }
        
        set<pair<llint, int>> q;
        q.insert({0, 0});
        
        while (!q.empty()) {
            auto cur_ = *q.begin();
            int cur = cur_.second;
            llint cur_dis = cur_.first;
            q.erase(q.begin());
            cout << cur << endl;
            if (dis[cur] != cur_dis) {
                continue;
            }
            
            for (auto& e : g[cur]) {
                int nxt = e.dst;
                llint cost = e.cost;
                cout << nxt << endl;
                if (dis[cur] + cost < dis[nxt]) {
                    dis[nxt] = dis[cur] + cost;
                    dp[nxt] = dp[cur];
                    if (!q.count({dis[nxt], nxt})) {
                        q.insert({dis[nxt], nxt});
                    }
                } else if (dis[cur] + cost == dis[nxt]) {
                    dp[nxt] = (1LL * dp[nxt] + dp[cur]) % MOD;
                }
            }
        }
        cout << dis[n - 1] << endl;
        return dp[n - 1];
    }
private:
    vector<llint> dis;
    vector<llint> dp;
    vector<Edge> g[N];
};
