def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

class Solution(object):
    def minOperations(self, nums):
        n = len(nums)
        if 1 in nums:
            cnt = 0
            for num in nums:
                if num != 1:
                    cnt += 1
            return cnt
        g = reduce(gcd, nums)
        if g != 1:
            return -1
        for i in xrange(1, n + 1):
            for j in xrange(n - i + 1):
                g = reduce(gcd, nums[j: j + i])
                if g == 1:
                    return i + n - 2
        return -1
