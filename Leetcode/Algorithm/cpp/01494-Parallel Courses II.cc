const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> dis(1 << n, INF);
        vector<vector<int> > g(n);
        vector<int> ind(n, 0);
        for (const auto& v: dependencies) {
            int a = v[0] - 1;
            int b = v[1] - 1;
            g[a].push_back(b);
            ind[b]++;
        }
        
        queue<int> q;
        q.push(0);
        dis[0] = 0;
        vector<int> curind(n);
        vector<int> candidates(n);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == (1 << n) - 1) {
                break;
            }
            curind = ind;
            for (int i = 0; i < n; i++) {
                if ((cur & (1 << i)) == 0) {
                    continue;
                }
                for (auto nxt: g[i]) {
                    curind[nxt]--;
                }
            }
            
            candidates.clear();
            for (int i = 0; i < n; i++) {
                if (!(cur & (1 << i)) && curind[i] == 0) {
                    candidates.push_back(i);
                }
            }
            
            int m = candidates.size();
            if (m < k) {
                int nxt = cur;
                for (auto c: candidates) {
                    nxt |= 1 << c;
                }
                if (dis[nxt] >= INF) {
                    dis[nxt] = dis[cur] + 1;
                    q.push(nxt);
                }
            } else {
                for (int i = 0; i < (1 << m); i++) {
                    if (__builtin_popcount(i) != k) {
                        continue;
                    }
                    int nxt = cur;
                    for (int j = 0; j < m; j++) {
                        if (i & (1 << j)) {
                            nxt |= 1 << (candidates[j]);
                        }
                    }
                    if (dis[nxt] >= INF) {
                        dis[nxt] = dis[cur] + 1;
                        q.push(nxt);
                    }
                }
            }
        }
        return dis[(1 << n) - 1];
    }
};
