from collections import defaultdict

class Solution(object):
    def beautySum(self, s):
        n = len(s)
        tot = 0
        for i in xrange(1, n + 1):
            d = defaultdict(int)
            for j in xrange(i - 1):
                d[s[j]] += 1
            for j in xrange(i - 1, n):
                d[s[j]] += 1
                tot += self.minmax(d)
                d[s[j - i + 1]] -= 1
        return tot
    
    def minmax(self, d):
        values = filter(lambda x: x, d.values())
        return max(values) - min(values)
