public class Solution {
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    public int longestCommonSubstring(String A, String B) {
        int la = A.length();
        int lb = B.length();
        int ans = 0;
        dp = new int[la + 5][lb + 5];
        
        for (int i = 1; i <= la; i++) {
            for (int j = 1; j <= lb; j++) {
                if (A.charAt(i - 1) == B.charAt(j - 1)) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                ans = Math.max(ans, dp[i][j]);
            }
        }
        return ans;
    }
    
    private int[][] dp;
}
