const int INF = 0x3f3f3f3f;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int> > g[2];
        g[0].resize(n);
        g[1].resize(n);
        
        for (const auto& v: red_edges) {
            int a = v[0];
            int b = v[1];
            
            g[0][a].push_back(b);
        }
       
        for (const auto& v: blue_edges) {
            int a = v[0];
            int b = v[1];
            
            g[1][a].push_back(b);
        }

        spfa(n, g);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = min(dis[0][i], dis[1][i]);
            
            if (ans[i] >= INF) {
                ans[i] = -1;
            }
        }
        return ans;
    }
private:
    void spfa(int n, vector<vector<int>> g[2]) {
        dis[0] = vector<int>(n, INF);
        dis[1] = vector<int>(n, INF);
        dis[0][0] = 0;
        dis[1][0] = 0;
        
        queue<pair<int, int> > q;
        q.push({0, 0});
        q.push({1, 0});
        
        map<pair<int, int>, int> inqueue;
        
        while (!q.empty()) {
            auto cur = q.front();
            int color = cur.first;
            int pos = cur.second;
            q.pop();
            
            inqueue[{color, pos}] = 0;
            
            int nextcolor = color ^ 1;
            for (auto next: g[nextcolor][pos]) {
                if (dis[color][pos] + 1 < dis[nextcolor][next]) {
                    dis[nextcolor][next] = dis[color][pos] + 1;
                    
                    if (inqueue[{nextcolor, next}] == 0) {
                        inqueue[{nextcolor, next}] = 1;
                        q.push({nextcolor, next});
                    }
                }
            }
        }          
    }
private:
    vector<int> dis[2];
};
