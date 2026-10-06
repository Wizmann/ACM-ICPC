class Solution(object):
    def minOperations(self, n):
        ave = n
        res = 0
        for i in xrange(n):
            cur = (2 * i) + 1
            res += abs(ave - cur)
        return res / 2


assert Solution().minOperations(3) == 2
assert Solution().minOperations(6) == 9
