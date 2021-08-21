from math import sqrt

class Solution(object):
    def countTriples(self, n):
        cnt = 0
        for a in xrange(1, n + 1):
            for b in xrange(a, n + 1):
                cc = (a * a + b * b)
                c = int(sqrt(cc))
                if c * c == cc and c <= n:
                    # print a, b, c
                    cnt += 1 if a == b else 2
        return cnt
