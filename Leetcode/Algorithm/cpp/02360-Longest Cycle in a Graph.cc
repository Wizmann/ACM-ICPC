const int SIZE = 123456;

vector<bool> visited;

class Solution {
public:
    int longestCycle(vector<int>& edges_) {
        edges = edges_;
        int n = edges.size();
        
        visited = vector<bool>(SIZE, false);
        res = 0;
        
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            map<int, int> mp;
            dfs(i, 0, mp);
        }
        
        return res == 0 ? -1 : res;
    }
private:
    void dfs(int cur, int step, map<int, int>& mp) {
        if (mp.count(cur)) {
            res = max(res, step - mp[cur]);
            return;
        }
        if (visited[cur]) {
            return;
        }
        mp[cur] = step;
        visited[cur] = true;
        int nxt = edges[cur];
        if (nxt == -1) {
            return;
        }
        dfs(nxt, step + 1, mp);
    }
    
    int res;
    vector<int> edges;    
};
