from collections import Counter

class Solution(object):
    def reductionOperations(self, nums):
        c = Counter(nums)
        pre = 0
        tot = 0
        for (key, count) in sorted(c.items(), reverse=True):
            tot += pre
            count += pre
            pre = count
        return tot
