const int INF = 0x3f3f3f3f;

struct Edge {
    int dest;
    int cost;
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, const int src, const int dst, int K) {
        dis = vector<vector<int> >(n, vector<int>(n + 1, INF));
        g = vector<vector<Edge> >(n);
        K++;
        
        for (auto flight: flights) {
            int a = flight[0];
            int b = flight[1];
            int c = flight[2];
            
            g[a].push_back({b, c});
        }
        
        queue<pair<int, int> > q;
        q.push({src, 0});
        dis[src][0] = 0;
        
        while (!q.empty()) {
            auto status = q.front();
            q.pop();
            
            int cur = status.first;
            int stop = status.second;
            
            if (stop >= K) {
                 continue;
            }
            
            auto iter = visit.find(status);
            if (iter != visit.end()) {
                visit.erase(iter);
            }
            
            for (auto next: g[cur]) {
                if (dis[cur][stop] + next.cost < dis[next.dest][stop + 1]) {
                    dis[next.dest][stop + 1] = dis[cur][stop] + next.cost;
                    if (visit.count({next.dest, stop + 1}) == 0) {
                        visit.insert({next.dest, stop + 1});
                        q.push({next.dest, stop + 1});
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 0; i <= K; i++) {
            cout << i << ' ' << dis[dst][i] << endl;
            ans = min(ans, dis[dst][i]);
        }
        return ans >= INF? -1: ans;
    }
private:
    vector<vector<Edge> > g;
    vector<vector<int> > dis;
    set<pair<int, int> > visit;
};
