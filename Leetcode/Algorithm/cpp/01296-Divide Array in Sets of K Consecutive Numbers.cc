class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset<int> st;
        for (auto num : nums) {
            st.insert(num);
        }
        bool flag = true;
        while (!st.empty()) {
            int mini = *st.begin();
            int cnt = 0;
            for (int i = 0; i < k; i++) {
                auto iter = st.find(mini + i);
                if (iter == st.end()) {
                    flag = false;
                    break;
                }
                st.erase(iter);
            }
        }
        return flag;
    }
};
