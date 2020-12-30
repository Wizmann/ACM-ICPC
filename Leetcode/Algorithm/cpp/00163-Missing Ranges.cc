typedef long long llint;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, llint lower, llint upper) {
        vector<string> res;

        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            if (i + 1 < n && nums[i] == nums[i + 1]) {
                continue;
            }
            llint num = i < n? nums[i]: 1LL + upper;
            if (lower == num) {
                lower++;
                continue;
            }
            if (num - lower == 1) {
                res.push_back(to_string(lower));
                lower = num + 1;
            } else {
                res.push_back(to_string(lower) + "->" + to_string(num - 1));
                lower = num + 1;
            }
        }
        return res;
    }
};
