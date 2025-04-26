INF = 10 ** 10

from collections import Counter

class Solution(object):
    def getLargestOutlier(self, nums):
        tot = sum(nums)
        c = Counter(nums)
        maxi = -INF
        for num in nums:
            c[num] -= 1
            tot -= num
            rem = tot - num

            if c.get(rem, 0):
                maxi = max(maxi, rem)

            tot += num
            c[num] += 1
        return maxi
        
