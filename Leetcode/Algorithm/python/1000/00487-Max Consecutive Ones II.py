class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        n = len(nums)
        ones = []
        l, r = 0, -1
        for i in xrange(n):
            if nums[i] == 1:
                r = i
            else:
                if l <= r:
                    ones.append((l, r))
                l, r = i + 1, -1
        if l <= r:
            ones.append((l, r))
        ans = 0
        m = len(ones)
        if not m and n:
            return 1
        for (l, r) in ones:
            ans = max(ans, r - l + 1 + (1 if l > 0 or r < n - 1 else 0))
        for i in xrange(m - 1):
            (l1, r1), (l2, r2) = ones[i], ones[i + 1]
            if r1 + 2 == l2:
                ans = max(ans, r2 - l1 + 1)
        return ans
