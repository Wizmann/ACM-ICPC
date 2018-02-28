const int INF = 0x3f3f3f3f;

class Solution {
public:
    /*
     * @param : the given array
     * @return: the minimum difference between their sums 
     */
    int findMin(vector<int> &nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        int h = (s + 1) / 2;
        vector<bool> dp(h + 1);
        dp[0] = true;
        
        int res = INF;
        for (auto num: nums) {
            for (int i = h; i >= 0; i--) {
                if (!dp[i] || i + num > h) {
                    continue;
                }
                int u = i + num;
                res = min(res, abs(s - 2 * u));
                dp[u] = true;
            }
        }
        return res;
    }
};
