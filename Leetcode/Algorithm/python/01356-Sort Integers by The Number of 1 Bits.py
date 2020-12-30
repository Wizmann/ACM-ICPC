# https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

from typing import *
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        count1 = lambda num: ('{:b}'.format(num).count('1'), num)
        return sorted(arr, key=count1)

S = Solution()
assert S.sortByBits([2, 1]) == [1, 2]
assert S.sortByBits([1]) == [1]
