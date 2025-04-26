from collections import defaultdict

class Solution(object):
    def sumDigitDifferences(self, nums):
        n = len(nums)
        res = 0
        for i in xrange(10):
            base = 10 ** i
            d = defaultdict(int)
            for num in nums:
                cur = (num % (base * 10)) / base
                d[cur] += 1
            tot = n * (n - 1) / 2
            for i in xrange(10):
                tot -= d[i] * (d[i] - 1) / 2
            res += tot
        return res
