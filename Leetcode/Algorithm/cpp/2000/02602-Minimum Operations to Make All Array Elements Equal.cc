typedef long long llint;

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        const int n = nums.size();
        vector<llint> ans;
        
        sort(nums.begin(), nums.end());
        vector<llint> prefix(n, 0);
        
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i];
            prefix[i] += prefix[i - 1];
        }
        
        for (auto query : queries) {
            auto iter = upper_bound(nums.begin(), nums.end(), query);
            int idx = iter - nums.begin();
            
            llint res = 0;
            if (idx) {
                res += (1LL * query * idx) - prefix[idx - 1];
            }
            res += (prefix[n - 1] - (idx - 1 >= 0? prefix[idx - 1]: 0)) - (1LL * query * (n - idx));
            ans.push_back(res);
        }
        return ans;
    }
};

