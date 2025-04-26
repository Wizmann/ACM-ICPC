from copy import deepcopy

MOD = (1000000000 + 7)

class Solution(object):
    def sumOfPower(self, nums, k):
        n = len(nums)
        d = {(0, 0): 1}
        for num in nums:
            for (a, b), c in d.items()[:]:
                aa = a + num
                if aa > k:
                    continue
                bb = b + 1
                d[(aa, bb)] = (d.get((aa, bb), 0) + c) % MOD
            # print d
        res = 0
        for (a, b), c in d.items():
            if a == k:
                res = (res + c * pow(2, n - b, MOD)) % MOD
        return res
