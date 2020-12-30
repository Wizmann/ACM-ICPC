class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for (auto num: nums) {
            st.insert(num);
            if (st.size() > 3) {
                st.erase(st.begin());
            }
        }
        return st.size() >= 3? *st.begin(): *st.rbegin();
    }
};
