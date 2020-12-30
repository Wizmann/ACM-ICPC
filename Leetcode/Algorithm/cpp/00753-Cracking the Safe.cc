class Solution {
public:
    string crackSafe(int n_, int k_) {
        n = n_;
        k = k_;
        m = pow(k, n);
        g.resize(m);
        
        for (int i = 0; i < m; i++) {
            int mask = pow(k, n - 1);
            int u = i % mask * k;
            for (int j = 0; j < k; j++) {
                if (i != u + j) {
                    g[i].push_back(u + j);
                }
            }
        }
        visit = vector<bool>(m, false);
        for (int i = 0; i < m; i++) {
            if (dfs(i, 1)) {
                return make_ans(i);
            }
        }
        return "fuck";
    }
private:
    bool dfs(int cur, int cnt) {
        if (cnt == m) {
            return true;
        }
        visit[cur] = true;
        for (auto next: g[cur]) {
            if (!visit[next]) {
                visit[next] = true;
                path.push_back(next);
                if (dfs(next, cnt + 1)) {
                    return true;
                }
                visit[next] = false;
                path.pop_back();
            }
        }
        visit[cur] = false;
        return false;
    }
    
    string make_ans(int start) {
        int mask = pow(k, n - 1);
        string ans = to_string(start / mask);
        for (auto p: path) {
            ans += to_string(p / mask);
        }
        int u = path.empty()? 0: *path.rbegin() % mask;
        for (int i = 1; i < n; i++) {
            int mask1 = pow(k, n - i - 1);
            ans += to_string(u / mask1);
            u %= mask1;
        }
        return ans;
    }
private:
    int n, k;
    int m;
    vector<bool> visit;
    vector<int> path;
    vector<vector<int> > g;
};
