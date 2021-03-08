from collections import defaultdict

INF = 10 ** 10

BITS = 10

class Solution(object):
    def minChanges(self, nums, k):
        n = len(nums)
        dp = [INF for i in xrange(1 << BITS)]
        dp[0] = 0
        
        for i in xrange(k):
            u = n / k + (1 if i < n % k else 0)
            mini = min(dp)
            dp1 = [mini + u for j in xrange(1 << BITS)]
            assert len(dp1) == (1 << BITS)
            d = defaultdict(int)
            for j in xrange(u):
                d[nums[k * j + i]] += 1
            for j in xrange(1 << BITS):
                for (key, value) in d.items():
                    dp1[j ^ key] = min(dp1[j ^ key], dp[j] + u - value)
            dp = dp1[:]
        return dp[0]
    
assert Solution().minChanges([26,19,19,28,13,14,6,25,28,19,0,15,25,11], 3) == 11
assert Solution().minChanges([1,2,4,1,2,5,1,2,6], 3) == 3
assert Solution().minChanges([1, 2, 0, 3, 0], 1) == 3
assert Solution().minChanges([3,4,5,2,1,7,3,4,7], 3) == 3
