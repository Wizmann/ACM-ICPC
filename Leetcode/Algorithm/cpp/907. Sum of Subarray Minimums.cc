const int MOD = 1000000000 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        set<int> st;
        vector<pair<int, int> > ns;
        const int n = A.size();
        
        for (int i = 0; i < n; i++) {
            ns.push_back({A[i], i});
        }
        sort(ns.begin(), ns.end());
        
        st.insert(-1);
        st.insert(n);
        
        int ans = 0;
        for (const auto& p: ns) {
            int cur = p.second;
            int l = cur - *prev(st.lower_bound(cur));
            int r = *st.upper_bound(cur) - cur;
            // cout << l * r << ' ' << p.first << endl;
            ans = (ans + 1LL * l * r * p.first % MOD) % MOD;
            st.insert(cur);
        }
        return ans;
    }
};
