from collections import defaultdict

N = 11111

class Solution(object):
    def deleteAndEarn(self, nums):
        d = defaultdict(int)
        for num in nums:
            d[num] += 1
            
        dp = [0 for i in xrange(N + 100)]
        
        for i in xrange(N, -1, -1):
            if i not in d:
                dp[i] = max(dp[i + 1], dp[i + 2])
                continue
            dp[i] = max(dp[i + 1], dp[i + 2] + d[i] * i)
        
        return max(dp)
            
