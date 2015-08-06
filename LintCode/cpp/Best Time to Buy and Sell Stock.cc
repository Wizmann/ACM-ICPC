class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        int mini = INF;
        
        for (auto price: prices) {
            mini = min(mini, price);
            ans = max(ans, price - mini);
        }
        return ans;
    }
private:
    int INF = 0x3f3f3f3f;
};

