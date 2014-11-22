public class Solution {
    public int lengthOfLastWord(String s) {
        int p = s.length() - 1;
        while (p >= 0 && s.charAt(p) == ' ') {
            p--;
        }
        int cnt = 0;
        while (p >= 0) {
            if (s.charAt(p) == ' ') {
                break;
            }
            p--;
            cnt++;
        }
        return cnt;
    }
}