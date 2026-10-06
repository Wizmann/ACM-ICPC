class Solution(object):
    def isSubsequence(self, s, t):
        s = list(s)
        t = list(t)
        while s and t:
            if s[-1] == t[-1]:
                s.pop()
            t.pop()
        return s == []
        
