class Solution {
public:
    /**
     * @param envelopes a number of envelopes with widths and heights
     * @return the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& e1, const pair<int, int>& e2) {
            if (e1.first != e2.first) {
                return e1 < e2;
            } else {
                return e1.second > e2.second;
            }
        });
        
        vector<int> st;
        for (const auto& item: envelopes) {
            int cur = item.second;
            
            if (!st.empty()) {
                auto iter = lower_bound(st.begin(), st.end(), cur);
                if (iter != st.end()) {
                    *iter = cur;
                } else {
                    st.push_back(cur);
                }
            } else {
                st.push_back(cur);
            }
        }
        
        return st.size();
    }
};
