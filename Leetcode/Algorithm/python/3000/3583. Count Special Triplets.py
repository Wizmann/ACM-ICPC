from collections import defaultdict

MOD = int(1e9 + 7)

class Solution(object):
    def specialTriplets(self, nums):
        left, right = defaultdict(int), defaultdict(int)

        for num in nums[1:]:
            right[num] += 1

        res = 0
        n = len(nums)
        for i in xrange(n):
            num = nums[i]
            a = left[num * 2]
            b = right[num * 2]
            # print num, a, b

            res += a * b % MOD
            res %= MOD

            left[num] += 1
            if i + 1 < n:
                right[nums[i + 1]] -= 1
        return res % MOD
