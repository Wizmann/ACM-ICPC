from collections import Counter

class Solution(object):
    def countElements(self, nums, k):
        c = sorted(Counter(nums).items(), reverse=True)
        pre = 0
        res = 0
        for (key, count) in c:
            if pre >= k:
                res += count
            pre += count
        return res
