# -*- coding:utf-8 -*-
class Solution:
    def jumpFloorII(self, number):
        dp = [0 for i in xrange(number + 1)]
        dp[0] = 1
        
        for i in xrange(number + 1):
            for j in xrange(i + 1, number + 1):
                dp[j] += dp[i]
        return dp[-1]
