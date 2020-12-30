class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        n = numCourses;
        g.resize(numCourses);
        in_degree.resize(numCourses);
        
        for (auto& p: prerequisites) {
            add_edge(p.second, p.first);
        }
        
        return top_sort();
    }

private:
    void add_edge(int a, int b) {
        g[a].push_back(b);
        in_degree[b]++;
    }
    
    vector<int> top_sort() {
        queue<int> q;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
                res.push_back(i);
            }
        }
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for(auto next: g[cur]) {
                in_degree[next]--;
                if (in_degree[next] == 0) {
                    q.push(next);
                    res.push_back(next);
                }
            }
        }
        
        int cnt = 0;
        for (auto i: in_degree) {
            if (i == 0) {
                cnt++;
            }
        }
        if (cnt == n) {
            return res;
        } else {
            return {};
        }
    }
private:
    int n;
    vector<vector<int> > g;
    vector<int> in_degree;
};
