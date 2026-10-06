class Solution(object):
    def isValid(self, S):
        st = []
        for c in S:
            st.append(c)
            if st[-3:] == list('abc'):
                st = st[:-3]
        return len(st) == 0
