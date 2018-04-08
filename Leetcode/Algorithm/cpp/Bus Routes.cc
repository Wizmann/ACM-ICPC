const int INF = 0x3f3f3f3f;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        vector<int> vs = {S};
        vector<int> vt = {T};
        
        routes.push_back(vs);
        routes.push_back(vt);
        
        n = routes.size();
        g = vector<vector<int> >(n);
        
        for (int i = 0; i < n; i++) {
            sort(routes[i].begin(), routes[i].end());
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (is_intersect(routes[i], routes[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        int res = spfa(n - 2, n - 1);
        
        if (res == INF) {
            return -1;
        }
        return res - 1;
    }
private:
    bool is_intersect(const vector<int>& va, const vector<int>& vb) {
        int la = va.size();
        int lb = vb.size();
        
        for (int p = 0, q = 0; p < la && q < lb; /* pass */) {
            if (va[p] == vb[q]) {
                return true;
            } else if (va[p] > vb[q]) {
                q++;
            } else {
                p++;
            }
         }
        
        return false;
    }
    
    int spfa(int st, int end) {
        queue<int> q;
        vector<int> dis(n, INF);
        vector<bool> visit(n, false);
        
        dis[st] = 0;
        q.push(st);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visit[cur] = false;
            
            for (auto next: g[cur]) {
                if (dis[cur] + 1 < dis[next]) {
                    dis[next] = dis[cur] + 1;
                    if (!visit[next]) {
                        visit[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        return dis[end];
    }
private:
    int n;
    vector<vector<int> > g;
};
