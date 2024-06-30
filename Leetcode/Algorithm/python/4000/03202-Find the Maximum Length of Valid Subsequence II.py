from collections import defaultdict

class Solution(object):
    def maximumLength(self, nums, k):
        nums = map(lambda x : x % k, nums)
        n = len(nums)
        ans = 0
        for mod in xrange(0, k):
            d = {}
            for i in xrange(k):
                d[i] = 0

            for i in xrange(n):
                cur = nums[i]
                pre = ((mod - cur) % k + k) % k
                d[cur] = max(d[cur], d[pre] + 1)
            ans = max(ans, max(d.values()))
        return ans
