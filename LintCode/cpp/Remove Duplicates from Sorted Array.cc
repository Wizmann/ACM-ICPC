class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        auto iter = unique(nums.begin(), nums.end());
        nums.erase(iter, nums.end());
        return nums.size();
    }
};
