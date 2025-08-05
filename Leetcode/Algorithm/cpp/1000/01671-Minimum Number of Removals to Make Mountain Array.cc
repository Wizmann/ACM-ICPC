class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        auto lis1 = get_lis(nums);
        reverse(nums.begin(), nums.end());
        auto lis2 = get_lis(nums);
        reverse(lis2.begin(), lis2.end());
        const int n = nums.size();
        
        /*
        for (int i = 0; i < n; i++) {
            printf("%d ", lis1[i]);
        }
        puts("");
        for (int i = 0; i < n; i++) {
            printf("%d ", lis2[i]);
        }
        puts("");
        */
        
        int maxi = 0;
        for (int i = 1; i < n - 1; i++) {
            if (lis1[i] == 1 || lis2[i] == 1) {
                continue;
            }
            maxi = max(maxi, lis1[i] + lis2[i] - 1);
        }
        return nums.size() - maxi;
    }
private:
    vector<int> get_lis(const vector<int>& nums) {
        const int n = nums.size();
        vector<int> st;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push_back(nums[i]);
                res[i] = st.size();
            } else {
                auto iter = lower_bound(st.begin(), st.end(), nums[i]);
                if (iter == st.end()) {
                    st.push_back(nums[i]);
                    res[i] = st.size();
                } else {
                    *iter = nums[i];
                    res[i] = distance(st.begin(), iter) + 1;
                }
            }
        }
        return res;
    }
};
