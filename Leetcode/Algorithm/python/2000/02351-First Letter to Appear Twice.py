class Solution(object):
    def repeatedCharacter(self, s):
        st = set()
        for c in s:
            if c in st:
                return c
            st.add(c)
        return '$'
