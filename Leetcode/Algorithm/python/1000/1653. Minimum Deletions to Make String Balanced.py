INF = 10 ** 10

class Solution(object):
    def minimumDeletions(self, s):
        n = len(s)
        A = s.count('a')
        B = n - A
        res = min(A, B)
        
        a, b = 0, 0
        for i in xrange(n):
            if s[i] == 'a':
                a += 1
            else:
                b += 1
            res = min(res, b + A - a)
        return res
