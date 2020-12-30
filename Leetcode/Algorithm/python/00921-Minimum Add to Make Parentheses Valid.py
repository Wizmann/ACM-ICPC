class Solution(object):
    def minAddToMakeValid(self, S):
        st = []
        for c in S:
            if c == ')' and st and st[-1] == '(':
                st.pop()
                continue
            st.append(c)
        return len(st)
