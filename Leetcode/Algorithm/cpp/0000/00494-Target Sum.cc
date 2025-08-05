class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if (n == 1) {
            int ans = 0;
            for (auto num: nums) {
                ans += (num == S || num == -S);
            }
            return ans;
        }
        
        int n1 = n / 2;
        int n2 = n - n1;
        
        map<int, int> m1 = calc(nums, 0, n1);
        map<int, int> m2 = calc(nums, n1, n);
        
        int ans = 0;
        for (auto& p: m1) {
            int v = p.first;
            int u = p.second;
            
            ans += u * m2[S - v];
        }
        return ans;
    }
        
    map<int, int> calc(vector<int>& nums, int l, int r) {
        map<int, int> mp;
        
        int n = r - l;
        for (int i = 0; i < (1 << n); i++) {
            int res = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    res += nums[j + l];
                } else {
                    res -= nums[j + l];
                }
            }
            mp[res]++;
        }
        return mp;
    }
};
