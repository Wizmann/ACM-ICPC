# https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

from typing import *
from collections import Counter

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        c = sorted(Counter(nums).items())
        d = {}
        pre = 0

        for (k, v) in c:
            d[k] = pre
            pre += v
        return list(map(lambda x: d[x], nums))


S = Solution()
assert S.smallerNumbersThanCurrent([8,1,2,2,3]) == [4,0,1,1,3]
assert S.smallerNumbersThanCurrent([8]) == [0]
assert S.smallerNumbersThanCurrent([8, 8]) == [0, 0]
