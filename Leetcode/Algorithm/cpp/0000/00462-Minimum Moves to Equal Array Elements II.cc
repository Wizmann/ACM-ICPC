class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        return accumulate(nums.begin(), nums.end(), 0, [&](const int x, const int y) {
            return x + abs(y - *(nums.begin() + n / 2));
        });
    }
};
