class Solution(object):
    def largestDivisibleSubset(self, nums):
        if not nums:
            return []
        nums.sort()
        n = len(nums)
        dp = [1 for i in xrange(n)]
        pre = [-1 for i in xrange(n)]
        for i in xrange(n):
            for j in xrange(0, i):
                a, b = nums[j], nums[i]
                if a * 2 > b:
                    break
                if b % a == 0:
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        pre[i] = j
        ans = max(dp)
        idx = dp.index(ans)
        res = []
        
        while idx != -1:
            res.append(idx)
            idx = pre[idx]
        
        return map(lambda x: nums[x], res[::-1])
                
