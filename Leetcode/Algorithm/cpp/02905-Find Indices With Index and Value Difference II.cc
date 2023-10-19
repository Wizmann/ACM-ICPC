class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        multiset<pair<int, int> > st;
        for (int i = indexDifference; i < n; i++) {
            st.insert({nums[i], i});
        }
        for (int i = 0; i < n && !st.empty(); i++) {
            int u = nums[i];
            auto mini = *st.begin();
            auto maxi = *st.rbegin();
            if (abs(u - mini.first) >= valueDifference) {
                return {i, mini.second};
            }
            if (abs(u - maxi.first) >= valueDifference) {
                return {i, maxi.second};
            }

            auto iter = st.find({nums[i + indexDifference], i + indexDifference});
            st.erase(iter);
        }
        return {-1, -1};
    }
};
