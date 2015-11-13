class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> st;
        for (auto num: nums) {
            if (st.empty()) {
                st.push_back(num);
            } else {
                auto iter = lower_bound(st.begin(), st.end(), num);
                if (iter == st.end()) {
                    st.push_back(num);
                } else {
                    *iter = num;
                }
            }
        }
        return st.size();
    }
};
