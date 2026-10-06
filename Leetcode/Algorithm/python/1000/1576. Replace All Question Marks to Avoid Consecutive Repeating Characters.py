import string
import random

class Solution(object):
    def modifyString(self, s):
        res = ''
        n = len(s)
        for i, c in enumerate(s):
            if c != '?':
                res += c
            else:
                st = set(string.ascii_lowercase)
                if i - 1 >= 0:
                    st.discard(res[-1])
                if i + 1 < n:
                    st.discard(s[i + 1])
                res += st.pop()
        return res
        
        
