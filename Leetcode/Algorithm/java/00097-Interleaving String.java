public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        
        if (l1 + l2 != l3) {
            return false;
        }
        if (l1 == 0) {
            return s2.equals(s3);
        }
        if (l2 == 0) {
            return s1.equals(s3);
        }
        
        int dp[][] = new int[l1 + 1][l2 + 1];
        dp[0][0] = 1;
        
        for (int i = 0; i <= l1; i++) {
            for (int j = 0; j <= l2; j++) {
                if (dp[i][j] == 0) {
                    continue;
                }
                int len = i + j;
                if (i < l1 && s1.charAt(i) == s3.charAt(len)) {
                    dp[i + 1][j] = 1;
                }
                if (j < l2 && s2.charAt(j) == s3.charAt(len)) {
                    dp[i][j + 1] = 1;
                }
            }
        }
        return dp[l1][l2] == 1;
    }
}