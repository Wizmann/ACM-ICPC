from collections import defaultdict

class Solution(object):
    def maxUncrossedLines(self, A, B):
        n = len(A)
        m = len(B)
        d = defaultdict(list)
        for i, b in enumerate(B):
            d[b].append(i)
            
        dp = [0 for i in xrange(m)]
        
        ans = 0
        for i, a in enumerate(A):
            for b in d[a][::-1]:
                dp[b] = max(dp[b], max(dp[:b] + [0]) + 1)
                ans = max(ans, dp[b])
        return ans
        
