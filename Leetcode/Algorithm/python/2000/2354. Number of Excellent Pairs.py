from collections import defaultdict

class Solution(object):
    def countExcellentPairs(self, nums, k):
        d = defaultdict(int)

        for num in set(nums):
            cnt = '{:b}'.format(num).count('1')
            d[cnt] += 1

        res = 0
        for key1, value1 in d.items():
            for key2, value2 in d.items():
                if key1 + key2 >= k:
                    res += value1 * value2
        return res
