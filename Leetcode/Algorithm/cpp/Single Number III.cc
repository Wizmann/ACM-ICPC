class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int u = accumulate(nums.begin(), nums.end(), 0, [](int a, int b) { return a ^ b; });
        auto iter = partition(nums.begin(), nums.end(), [&](int x) { return bool(x & lowbit(u)); });
        return {
            accumulate(nums.begin(), iter, 0, [](int a, int b) { return a ^ b; }),
            accumulate(iter, nums.end(), 0, [](int a, int b) { return a ^ b; })
        };
    }
private:
    inline int lowbit(int x) {
        return x & (-x);
    }
};
