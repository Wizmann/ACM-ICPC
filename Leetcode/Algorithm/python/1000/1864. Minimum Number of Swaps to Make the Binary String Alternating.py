INF = 10 ** 10

class Solution(object):
    def minSwaps(self, s):
        res = INF
        s = map(int, s)
        res = min(res, self.solve(s))
        s = map(lambda x: x ^ 1, s)
        res = min(res, self.solve(s))
        return -1 if res == INF else res
    
    def solve(self, s):
        n = len(s)
        zeros, ones = 0, 0
        for i in xrange(n):
            if s[i] == 1 and i % 2 == 0:
                ones += 1
            elif s[i] == 0 and i % 2 == 1:
                zeros += 1
        if ones != zeros:
            return INF
        return ones
        
