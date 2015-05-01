class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        st = set()
        (p, q) = (0, 0)
        ans = 0
        for c in s:
            if c not in st:
                st.add(c)
                q += 1
                ans = max(ans, q - p)
            else:
                while p < q and c in st:
                    st.remove(s[p])
                    p += 1
                st.add(c)
                q += 1
        return ans
            
