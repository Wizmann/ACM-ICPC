class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& ts) {
        int n = ts.size();
        vector<int> res(n);
        vector<pair<int, int> > ps;
        
        for (int i = 0; i < n; i++) {
            ps.push_back({ts[i], i});
        }
        
        sort(ps.begin(), ps.end(), [](const pair<int, int>& pa, const pair<int, int>& pb) {
            if (pa.first != pb.first) {
                return pa.first > pb.first;
            } else {
                return pa.second < pb.second;
            }
        });
        
        set<int> st;
        for (int i = 0; i < n; i++) {
            int value = ps[i].first;
            int pos = ps[i].second;
            
            auto iter = st.upper_bound(pos);
            if (iter == st.end()) {
                res[pos] = 0;
            } else {
                res[pos] = *iter - pos;
            }
            
            st.insert(pos);
        }
        
        return res;
    }
private:
    map<int, int> mp;
};
