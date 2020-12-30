const int INF = 0x3f3f3f3f;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet_) {
        quiet = quiet_;
        n = quiet.size();
        
        g.resize(n);

        for (const auto& v: richer) {
            int x = v[0];
            int y = v[1];
                        
            g[x].push_back(y);
        }

        vector<int> roots;
        for (int i = 0; i < n; i++) {
            roots.push_back(i);
        }
        sort(roots.begin(), roots.end(), [&](int a, int b) {
            return quiet[a] < quiet[b];
        });
        
        ans = vector<int>(n, INF);
        for (auto root: roots) {
            dfs(root, quiet[root], root);
        }
        return ans;
    }
private:
    void dfs(int cur, int mini, int p) {
        if (ans[cur] == INF) {
            ans[cur] = p;
        } else {
            return;
        }
        
        for (auto next: g[cur]) {
            dfs(next, mini, p);
        }
    }
private:
    int n;
    vector<int> quiet;
    vector<vector<int> > g;
    vector<int> ans;
};
