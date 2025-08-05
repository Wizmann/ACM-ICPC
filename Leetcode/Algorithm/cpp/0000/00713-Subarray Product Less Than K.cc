typedef long long llint;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        deque<int> dq;
        
        int n = nums.size();
        int ans = 0;
        llint mul = 1;
        
        for (int i = 0; i < n; i++) {
            mul *= nums[i];
            dq.push_back(nums[i]);
            
            while (!dq.empty() && mul >= k) {
                int u = *dq.begin();
                mul /= u;
                dq.pop_front();
                
                ans += dq.size();
            }
        }
        while (!dq.empty()) {
            ans += dq.size();
            dq.pop_front();
        }
        return ans;
    }
};
