public class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> st = new HashSet<>();
        int p = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            while (st.contains(c)) {
                st.remove(s.charAt(p));
                p++;
            }
            st.add(c);
            ans = Math.max(ans, st.size());
        }
        return ans;
    }
}
