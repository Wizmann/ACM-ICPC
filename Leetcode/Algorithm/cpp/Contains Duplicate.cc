class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for_each(nums.begin(), nums.end(), [&](const int u) {
            st.insert(u);
        });
        return st.size() != nums.size();
    }
};
