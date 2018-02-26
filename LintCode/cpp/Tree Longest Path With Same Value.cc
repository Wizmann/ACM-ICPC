class Solution {
public:
    /*
     * @param : as indicated in the description
     * @param : as indicated in the description
     * @return: Return the number of edges on the longest path with same value.
     */
    int LongestPathWithSameValue(vector<int> &A, vector<int> &E) {
        ans = 0;
        tags = A;
        n = A.size();
        g = vector<vector<int> >(n + 1);
        
        int m = E.size();
        for (int i = 0; i < m; i += 2) {
            int a = E[i];
            int b = E[i + 1];
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        int ph_value; // placeholder
        int ph_count; // placeholder
        dfs(-1, 0, ph_value, ph_count);
        
        return ans;
    }
private:
    void dfs(int pre, int cur, int& value, int &count) {
        int cv = tags[cur];
        int a = 0;
        int b = 0;
        for (auto next: g[cur]) {
            if (next == pre) {
                continue;
            }
            int v, c;
            dfs(cur, next, v, c);
            
            if (v == cv) {
                if (c > a) {
                    b = a;
                    a = c;
                } else if (c > b) {
                    b = c;
                }
            }
        }

        ans = max(ans, a + b);
        
        value = cv;
        count = 1 + a;
    }
private:
    int ans;
    int n;
    vector<int> tags;
    vector<vector<int> > g;
};
