class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> idx(n, 0);
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](const int a, const int b) {
            return nums[a] < nums[b];
        });
        int p = 0;
        int q = n - 1;
        while (p < q) {
            int s = nums[idx[p]] + nums[idx[q]];
            if (s > target) {
                q--;
            } else if (s < target) {
                p++;
            } else {
                return {min(idx[p], idx[q]) + 1, max(idx[p], idx[q]) + 1};
            }
        }
        return {};
    }
};
