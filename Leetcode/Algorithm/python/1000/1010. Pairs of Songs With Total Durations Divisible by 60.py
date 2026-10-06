from collections import defaultdict

class Solution(object):
    def numPairsDivisibleBy60(self, time):
        d = defaultdict(int)
        for t in time:
            d[t % 60] += 1
        ans = 0
        for i in xrange(1, 30):
            ans += d[i] * d[60 - i]
        ans += d[30] * (d[30] - 1) / 2 + d[0] * (d[0] - 1) / 2
        return ans
