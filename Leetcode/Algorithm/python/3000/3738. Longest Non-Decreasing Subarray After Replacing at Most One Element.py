INF = 10 ** 10

class Solution(object):
    def longestSubarray(self, nums):
        n = len(nums)
        ans = 0
        # a - subarray w/o replacing element
        # b - subarray with replacing element on position (i - 1)
        # c - subarray with replacing element on position (< i - 1)
        a1, b1, c1 = (0, -INF, -INF)
        for i in xrange(n):
            pre = -INF if i - 1 < 0 else nums[i - 1]
            cur = nums[i]
            a2, b2, c2 = 1, 0, (0 if i == 0 else 2)

            if i - 2 >= 0 and cur >= nums[i - 2]:
                c2 = max(c2, b1 + 1)            
            if pre <= cur:
                a2 = max(a2, a1 + 1)
                c2 = max(c2, c1 + 1)
            else:
                b2 = max(b2, a1 + 1)
                if i - 2 >= 0 and cur >= nums[i - 2]:
                    c2 = max(c2, a1 + 1)
            ans = max(ans, a2, b2, c2)
            a1, b1, c1 = a2, b2, c2
        return ans

