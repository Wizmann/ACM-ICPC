public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        HashSet<Character> hs = new HashSet<Character>();
        int p = 0, q = 0;
        int ans = 0;
        while (q < n) {
            while (p < q && hs.contains(s.charAt(q))) {
                hs.remove(s.charAt(p));
                p++;
            }
            hs.add(s.charAt(q));
            q++;
            ans = Math.max(ans, q - p);
        }
        return ans;
    }
}