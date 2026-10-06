class Solution(object):
    def minimumSwap(self, s1, s2):
        s1, s2 = list(s1), list(s2)
        
        n = len(s1)
        a, b = 0, 0
        for i in xrange(n):
            if s1[i] == s2[i]:
                continue
            if s1[i] == 'x' and s2[i] == 'y':
                a += 1
            elif s1[i] == 'y' and s2[i] == 'x':
                b += 1
            else:
                assert False
                
        cnt = a / 2 + b / 2
        if (a % 2) ^ (b % 2) == 1:
            return -1
        cnt += (a % 2) + (b % 2)
        return cnt
