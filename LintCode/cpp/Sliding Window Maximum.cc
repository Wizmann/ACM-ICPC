class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> dq;
        vector<int> res;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int u = nums[i]; 
            while (!dq.empty() && u > nums[*dq.rbegin()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            while (!dq.empty() && *dq.begin() <= i - k) {
                dq.pop_front();
            }
            if (i >= k - 1) {
                res.push_back(nums[*dq.begin()]);
            }
        }
        return res;
    }
};

