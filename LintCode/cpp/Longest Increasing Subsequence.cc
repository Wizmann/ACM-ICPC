class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        vector<int> st;
        for (auto num: nums) {
            if (st.empty() || num >= *st.rbegin()) {
                st.push_back(num);
                continue;
            } else {
                auto iter = lower_bound(st.begin(), st.end(), num);
                *iter = num;
            }
        }
        return st.size();
    }
};

