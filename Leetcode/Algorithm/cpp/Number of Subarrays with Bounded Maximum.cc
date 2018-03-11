class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        map<int, vector<int> > mp;
        const int n = A.size();
        for (int i = 0; i < n; i++) {
            mp[A[i]].push_back(i + 1);
        }
        
        set<int> st;
        st.insert(0);
        st.insert(n + 1);
        
        int res = 0;
        for (auto iter = mp.rbegin(); iter != mp.rend(); iter++) {
            if (L <= iter->first && iter->first <= R) {
                for (auto pos: iter->second) {
                    auto p = st.upper_bound(pos);
                    auto q = p;
                    --q;
                    
                    int l = *q + 1;
                    int r = *p - 1;

                    res += (pos - l + 1) * (r - pos + 1);
                    
                    st.insert(pos);
                }
            } else {
                for (auto pos: iter->second) {
                    st.insert(pos);
                }
            }
        }
        return res;
    }
};
