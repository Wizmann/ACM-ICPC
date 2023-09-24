class Solution(object):
    def finalString(self, s):
        st = []
        for c in s:
            if c == 'i':
                st = st[::-1]
            else:
                st.append(c)
        return ''.join(st)
