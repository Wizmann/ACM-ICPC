MOD = (10 ** 9) + 7

class Solution(object):
    def maxSum(self, nums, k):
        res = [0 for i in xrange(k)]
        for i in xrange(32):
            ns = map(lambda x: x & (1 << i), nums)
            ns.sort(reverse=True)
            for j in xrange(k):
                res[j] += ns[j]
        ans = 0
        for i in xrange(k):
            ans = (ans + res[i] ** 2) % MOD
        return ans
