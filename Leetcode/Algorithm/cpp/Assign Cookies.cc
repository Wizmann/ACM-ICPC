class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        
        int ans = 0;
        while (!g.empty() && !s.empty()) {
            int gg = *g.rbegin();
            int ss = *s.rbegin();
            
            if (ss >= gg) {
                g.pop_back();
                s.pop_back();
                ans++;
            } else {
                s.pop_back();
            }
        }
        return ans;
    }
};
