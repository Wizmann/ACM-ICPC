class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        vector<int> st;
        for (auto num: nums) {
            if (st.empty() || *st.rbegin() < num) {
                st.push_back(num);
                continue;
            }
            auto iter = lower_bound(st.begin(), st.end(), num);
            *iter = num;
        }
        return st.size() >= nums.size() - 1;
    }
};
