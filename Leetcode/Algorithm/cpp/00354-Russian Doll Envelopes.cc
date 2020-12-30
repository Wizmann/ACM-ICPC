class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> pa, pair<int, int> pb) {
            if (pa.first != pb.first) {
                return pa.first < pb.first;
            } else {
                return pa.second > pb.second;
            }
        });
        vector<int> st;
        for (const auto& env: envelopes) {
            int cur = env.second;
            if (st.empty() || cur > *st.rbegin()) {
                st.push_back(cur);
            } else {
                auto iter = lower_bound(st.begin(), st.end(), cur);
                *iter = cur;
            }
        }
        return st.size();
    }
};
