class Solution(object):
    def checkIfCanBreak(self, s1, s2):
        s1 = ''.join(sorted(s1))
        s2 = ''.join(sorted(s2))
        n = len(s1)
        b1 = [s1[i] <= s2[i] for i in xrange(n)]
        b2 = [s1[i] >= s2[i] for i in xrange(n)]
        
        return len(set(b1)) == 1 or len(set(b2)) == 1
        
