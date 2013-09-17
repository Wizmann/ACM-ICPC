const size_t SIZE = 51200;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        
        int n = prices.size();
        
        int mini = INF, maxi = 0;
        for (int i = 0; i < n; i++) {
            mini = min(mini, prices[i]);
            left[i] = prices[i] - mini;
            if (i - 1 >= 0) {
                left[i] = max(left[i], left[i - 1]);
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            maxi = max(maxi, prices[i]);
            right[i] = maxi - prices[i];
            if (i + 1 < n) {
                right[i] = max(right[i], right[i + 1]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, left[i] + right[i]);
        }
        return ans;
    }
    int left[SIZE], right[SIZE];
};
