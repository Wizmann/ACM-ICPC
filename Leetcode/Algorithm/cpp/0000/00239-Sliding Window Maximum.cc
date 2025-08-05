class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int u = nums[i];
            while (!dq.empty() && nums[*dq.rbegin()] <= u) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            if (k <= i + 1) {
                while (i - *dq.begin() + 1 > k) {
                    dq.pop_front();
                }
                res.push_back(nums[*dq.begin()]);
            }
        }
        return res;
    }
};
