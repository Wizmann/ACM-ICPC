class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        if (nums.empty()) {
            return 0;
        }
        
        queue<int> q;
        int sum = 0;
        int mini = numeric_limits<int>::max();
        
        for (auto i: nums) {
            q.push(i);
            sum += i;
            
            while (sum >= s) {
                mini = min(mini, static_cast<int>(q.size()));
                auto j = q.front();
                q.pop();
                sum -= j;
            }
        }
        return mini == numeric_limits<int>::max()? 0: mini;
    }
};
