class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for (int i = 0; i < 20; i++) {
            int u = nums[rand() % n];
            int cnt = 0;
            for (auto i: nums) {
                cnt += u == i;
            }
            
            if (cnt > n / 3) {
                st.insert(u);
            }
        }
        vector<int> res;
        copy(st.begin(), st.end(), back_inserter(res));
        return res;
    }
};
