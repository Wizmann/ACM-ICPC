class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        queue<int> q;
        int sum = 0;
        size_t ans = numeric_limits<size_t>::max();
        
        for (auto i: nums) {
            q.push(i);
            sum += i;
            
            while (sum >= s) {
                ans = min(ans, q.size());
                int u = q.front();
                q.pop();
                
                sum -= u;
            }
        }
        if (ans == numeric_limits<size_t>::max()) {
            return 0;
        }
        return ans;
    }
};
