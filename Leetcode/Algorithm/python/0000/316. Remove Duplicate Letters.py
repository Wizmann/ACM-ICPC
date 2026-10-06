class Solution(object):
    def removeDuplicateLetters(self, s):
        d = {}
        st = []
        for (i, c) in enumerate(s):
            d[c] = i
        
        for (i, c) in enumerate(s):
            if c in st:
                continue
            while st and c < st[-1] and d[st[-1]] > i:
                st.pop()
            st.append(c)
        return ''.join(st)
        
