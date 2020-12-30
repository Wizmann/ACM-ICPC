class Solution {
    struct Edge {
        double param;
        int dest;
    };

    vector<int> fathers;
    unordered_map<string, int> nodes_mp;
    vector<vector<Edge> > g;
    unordered_map<int, double> results;
    int idx = 1;
    
    const int MAGIC = 100;

    int find_father(int x) {
        if (fathers[x] == x) {
            return x;
        }
        return fathers[x] = find_father(fathers[x]);
    }
    
    void dfs(int p, double v) {
        results[p] = v;
        for (const auto& e: g[p]) {
            int next = e.dest;
            double p = e.param;
            
            if (results.find(next) != results.end()) {
                continue;
            }
            dfs(next, v * p);
        }
    }
    
public:
    vector<double> calcEquation(
            vector<pair<string, string>> equations, 
            vector<double>& values, 
            vector<pair<string, string>> queries) {
        for (const auto& equa: equations) {
            const string& sa = equa.first;
            const string& sb = equa.second;
            
            if (nodes_mp.find(sa) == nodes_mp.end()) {
                nodes_mp[sa] = idx++;
            }
            if (nodes_mp.find(sb) == nodes_mp.end()) {
                nodes_mp[sb] = idx++;
            }
        }
        g.resize(idx + 1);
        fathers.resize(idx + 1);
        for (int i = 0; i < idx + 1; i++) {
            fathers[i] = i;
        }
        
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            const auto& equa = equations[i];
            
            const string& sa = equa.first;
            const string& sb = equa.second;
            
            int a = nodes_mp[sa];
            int b = nodes_mp[sb];
            
            fathers[find_father(a)] = find_father(b);
            
            g[a].push_back({1.0 / values[i], b});
            g[b].push_back({values[i], a});
        }
        
        for (int i = 1; i < idx; i++) {
            if (results.find(i) == results.end()) {
                dfs(i, MAGIC);
            }
        }
        
        vector<double> answers;
        for (const auto& query: queries) {
            const string& sa = query.first;
            const string& sb = query.second;
            
            int a = nodes_mp[sa];
            int b = nodes_mp[sb];
            
            if (results.find(a) == results.end() || results.find(b) == results.end()) {
                answers.push_back(-1.0);
            } else if (find_father(a) != find_father(b)) {
                answers.push_back(-1.0);  
            } else {
                answers.push_back(results[a] / results[b]);
            }
        }
        return answers;
    }
};
