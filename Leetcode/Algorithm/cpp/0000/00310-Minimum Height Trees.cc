class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        g.resize(n);
        for (auto edge: edges) {
            int a = edge.first;
            int b = edge.second;
            g[a].push_back({b, -1});
            g[b].push_back({a, -1});
        }
        
        mini = numeric_limits<int>::max();
        dfs1(0, -1);
        dfs2(0, -1, 0);
        
        return ans;
    }
private:
    int dfs1(int cur, int pre) {
        int res = 0;
        for (auto& item: g[cur]) {
            if (item.first == pre) {
                continue;
            }
            item.second = dfs1(item.first, cur) + 1;
            res = max(res, item.second);
        }
        return res;
    }
    
    void dfs2(int cur, int pre, int maxi) {
        int cur_maxi = maxi;
        multiset<int> st;
        st.insert(maxi);
        for (auto item: g[cur]) {
            if (item.first == pre) {
                continue;
            }
            st.insert(item.second);
            cur_maxi = max(cur_maxi, item.second);
        }

        if (cur_maxi < mini) {
            mini = cur_maxi;
            ans = { cur };
        } else if (cur_maxi == mini) {
            ans.push_back(cur);
        }
        
        for (auto item: g[cur]) {
            if (item.first == pre) {
                continue;
            }
            int u = -1;
            if (item.second == *st.rbegin()) {
                u = *(++st.rbegin());
            } else {
                u = *st.rbegin();
            }
            dfs2(item.first, cur, u + 1);
        }
    }
private:
    vector<vector<pair<int, int> > > g;
    int mini;
    vector<int> ans;
};
