using llint = long long;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<llint> st;
        for (auto num : nums) {
            st.insert(num);
        }

        int step = 0;
        while (st.size() >= 2 && *st.begin() < k) {
            llint a = *st.begin();
            st.erase(st.begin());
            llint b = *st.begin();
            st.erase(st.begin());

            llint c = min(a, b) * 2 + max(a, b);
            st.insert(c);
            step++;
        }
        return step;
    }
};
