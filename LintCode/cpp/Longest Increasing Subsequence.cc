class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        vector<int> vec;
        int ans = 0;
        for (auto num: nums) {
            if (vec.empty() || num >= *vec.rbegin()) {
                vec.push_back(num);
            } else {
                auto iter = lower_bound(vec.begin(), vec.end(), num);
                *iter = num;
            }
            ans = max(ans, (int)vec.size());
        }
        return ans;
    }
};

