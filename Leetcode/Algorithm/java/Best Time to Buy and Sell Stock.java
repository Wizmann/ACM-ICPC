public class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int left_mini[]  = new int[n];
        int right_maxi[] = new int[n];
        
        for (int i = 0, mini = INF; i < n; i++) {
            mini = Math.min(mini, prices[i]);
            left_mini[i] = mini;
        }
        for (int i = n - 1, maxi = -INF; i >= 0; i--) {
            maxi = Math.max(maxi, prices[i]);
            right_maxi[i] = maxi;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, right_maxi[i] - left_mini[i]);
        }
        return ans;
    }
    
    private int INF = 0x3f3f3f3f;
}