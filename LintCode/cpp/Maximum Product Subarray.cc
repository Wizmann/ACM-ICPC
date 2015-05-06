class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        int mini = 1;
        int maxi = 1;
        int ans = -INF;
        for (auto num: nums) {
            mini *= num;
            maxi *= num;
            
            auto tuple = {ans, maxi, mini, num};
            ans = accumulate(
                tuple.begin(), tuple.end(), -INF,
                [](const int& a, const int& b) {
                    return max(a, b);
                });
            
            int _maxi = max(max(maxi, mini), num);
            int _mini = min(min(maxi, mini), num);
            maxi = _maxi;
            mini = _mini;
        }
        return ans;
    }
private:
    static const int INF = 0x3f3f3f3f;
};
