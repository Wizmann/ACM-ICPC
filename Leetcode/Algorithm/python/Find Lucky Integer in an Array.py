# https://leetcode.com/problems/find-lucky-integer-in-an-array/

from collections import Counter

class Solution:
    def findLucky(self, arr: List[int]) -> int:
        c = Counter(arr)
        res = -1
        for key, value in c.items():
            if key == value:
                res = max(res, key)
        return res
