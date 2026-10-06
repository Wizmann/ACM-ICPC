MOD = (10 ** 9) + 7
class Solution(object):
    def maxSumRangeQuery(self, nums, requests):
        nums.sort(reverse=True)
        n = len(nums)
        cnt = [0 for i in xrange(n)]
        for (a, b) in requests:
            cnt[b] += 1
            if a - 1 >= 0:
                cnt[a - 1] -= 1
        for i in xrange(n - 2, -1, -1):
            cnt[i] += cnt[i + 1]
        cnt.sort(reverse=True)
        res = 0
        for i in xrange(n):
            res += cnt[i] * nums[i] % MOD
            res %= MOD
        return res
        
        
