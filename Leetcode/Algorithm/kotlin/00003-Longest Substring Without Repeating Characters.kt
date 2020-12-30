class Solution {
    fun lengthOfLongestSubstring(s: String): Int {
        var st = HashSet<Char>()
        val n = s.length
        
        var l = 0
        var r = 0
        var res = 0
        
        while (l < n && r < n) {
            val cur = s[r]
            while (st.contains(cur)) {
                st.remove(s[l])
                l++
            }
            st.add(s[r])
            r++;
            res = maxOf(res, r - l)
        }
        return res
    }
}
