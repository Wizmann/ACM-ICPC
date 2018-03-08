const int INF = 0x3f3f3f3f;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        n = org.size();
        g.resize(n + 1);
        
        int st = *org.begin();
        bool flag = false;
        for (const auto& seq: seqs) {
            int m = seq.size();
            if (!seq.empty() && *seq.begin() == st) {
                flag = true;
            }
            for (int i = 0; i < m; i++) {
                if (seq[i] <= 0 || seq[i] > n) {
                    return false;
                }
            }
            for (int i = 0; i + 1 < m; i++) {
                int a = seq[i];
                int b = seq[i + 1];
                if (a >= 1 && a <= n && b >= 1 && b <= n) {
                    if (a == st) {
                        flag = true;
                    }
                    g[a].push_back(b);
                }
            }
        }
        
        if (!flag) {
            return false;
        }
        
        if (!spfa(st)) {
            return false;
        }
        for (int i = 0; i + 1 < n; i++) {
            int a = org[i];
            int b = org[i + 1];
            if (dis[a] == -INF || dis[b] == -INF || dis[a] >= dis[b]) {
                return false;
            }
        }
        return true;
    }
private:
    bool spfa(int st) {
        queue<int> q;
        q.push(st);
        dis = vector<int>(n + 1, -INF);
        dis[st] = 0;
        visit = vector<bool>(n + 1, false);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visit[cur] = false;
            
            if (dis[cur] > n) {
                return false;
            }
            
            for (auto next: g[cur]) {
                if (dis[cur] + 1 > dis[next]) {
                    dis[next] = dis[cur] + 1;
                    if (!visit[next]) {
                        visit[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        return true;
    }
private:
    int n;
    vector<vector<int> > g;
    vector<int> dis;
    vector<bool> visit;
};
