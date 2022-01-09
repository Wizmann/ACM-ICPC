from typing import *

INF = 10 ** 10

class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        minp = -1
        minn = INF
        n = len(nums)
        cur = 1
        res = 0
        for i in range(n):
            cur *= nums[i]
            if cur > 0:
                cur = 1
            elif cur < 0:
                cur = -1
            if cur > 0:
                res = max(res, i - minp)
                minp = min(minp, i)
            elif cur < 0:
                res = max(res, i - minn)
                minn = min(minn, i)
            else:
                minp = i
                minn = INF
                cur = 1
        return res
