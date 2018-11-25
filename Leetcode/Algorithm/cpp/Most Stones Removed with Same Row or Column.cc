class Solution {
public:
    int removeStones(vector<vector<int>>& stones_) {
        stones = stones_;
        int n = stones.size();
        
        for (int i = 0; i < n; i++) {
            int x = stones[i][0];
            int y = stones[i][1];
            
            mpx[x].push_back(i);
            mpy[y].push_back(i);
        }
        
        visited = vector<bool>(n, false);
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            cnt++;
            dfs(i);
        }
        return n - cnt;
    }
private:
    void dfs(int cur) {
        if (visited[cur]) {
            return;
        }
        
        visited[cur] = true;
        
        int x = stones[cur][0];
        int y = stones[cur][1];
        
        for (auto nx: mpx[x]) {
            dfs(nx);
        }
        
        for (auto ny: mpy[y]) {
            dfs(ny);
        }
    }
private:
    vector<vector<int> > stones;
    vector<bool> visited;
    map<int, vector<int> > mpx, mpy;
};
