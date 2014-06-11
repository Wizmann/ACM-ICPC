const int INF = 1 << 29;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> leftmin, rightmax;
        int n = prices.size();
        for (int i = 0, j = INF; i < n; i++) {
            if (prices[i] < j) {
                j = prices[i];
            }
            leftmin.push_back(j);
        }
        for (int i = n - 1, j = -INF; i >= 0; i--) {
            if (prices[i] > j) {
                j = prices[i];
            }
            rightmax.push_back(j);
        }
        reverse(rightmax.begin(), rightmax.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, rightmax[i] - leftmin[i]);
        }
        return ans;
    }
};
