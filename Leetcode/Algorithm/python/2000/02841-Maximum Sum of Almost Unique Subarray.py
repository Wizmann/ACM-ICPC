class Solution(object):
    def maxSum(self, nums, m, k):
        d = {}
        n = len(nums)
        maxi = 0
        pre = nums[:]
        for i in xrange(1, n):
            pre[i] += pre[i - 1]
        for i in xrange(n):
            d[nums[i]] = d.get(nums[i], 0) + 1
            if i - k >= 0:
                d[nums[i - k]] -= 1
                if not d[nums[i - k]]:
                    del d[nums[i - k]]
            if i + 1 >= k and len(d) >= m:
                # print d, pre, i
                maxi = max(maxi, pre[i] - (0 if i + 1 == k else pre[i + 1 - k - 1]))
        return maxi
