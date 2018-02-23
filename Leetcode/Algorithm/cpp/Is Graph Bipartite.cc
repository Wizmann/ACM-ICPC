class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        map<int, int> mp;
        int n = graph.size();
        
        for (int i = 0; i < n; i++) {
            int color = 0;
            if (mp.count(i) != 0) {
                continue;
            }
            
            queue<pair<int, int> > q;
            q.push({i, 0});
            while (!q.empty()) {
                auto cur = q.front();
                int p = cur.first;
                int c = cur.second;
                q.pop();
                
                if (mp.count(p) > 0 && mp[p] != c) {
                    return false;
                }
                
                if (mp.count(p) > 0) {
                    continue;
                }
                
                mp[p] = c;
                for (auto next: graph[p]) {
                    q.push({next, c ^ 1});
                }
            }
        }
        return true;
    }
};
