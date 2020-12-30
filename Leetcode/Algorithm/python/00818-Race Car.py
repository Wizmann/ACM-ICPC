INF = 10 ** 10

class Solution(object):
    def __init__(self):
        self.dp = [0] + [INF for i in xrange(10000)]

    def racecar(self, target):
        if self.dp[target] != INF:
            return self.dp[target]

        l = len("{:b}".format(target))
        if target == (1 << l) - 1:
            self.dp[target] = l
            return l
        
        self.dp[target] = self.racecar((1 << l) - 1 - target) + l + 1
        for i in xrange(l):
            self.dp[target] = min(self.dp[target], self.racecar(target - (1 << (l - 1)) + (1 << i)) + l + i + 1)
        return self.dp[target]
