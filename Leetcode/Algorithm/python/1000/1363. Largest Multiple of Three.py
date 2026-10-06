# https://leetcode.com/problems/largest-multiple-of-three/

from typing import *

class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        tot = sum(digits)
        digits.sort(reverse=True)
        if tot % 3 == 0:
            if tot == 0:
                return '0'
            return ''.join(map(str, digits))

        rem = [ [], [], [] ]

        for d in digits:
            rem[d % 3].append(d)

        if tot % 3 == 1:
            if len(rem[1]) >= 1:
                rem[1].pop()
            elif len(rem[2]) >= 2:
                rem[2].pop()
                rem[2].pop()
            else:
                rem[1] = []
                rem[2] = []
        elif tot % 3 == 2:
            if len(rem[2]) >= 1:
                rem[2].pop()
            elif len(rem[1]) >= 2:
                rem[1].pop()
                rem[1].pop()
            else:
                rem[1] = []
                rem[2] = []
        else:
            assert False

        digits = rem[0] + rem[1] + rem[2]
        if not digits:
            return ''
        if sum(digits) == 0:
            return '0'
        digits.sort(reverse=True)
        return ''.join(map(str, digits))

S = Solution()
assert S.largestMultipleOfThree([1, 1]) == ''
assert S.largestMultipleOfThree([0]) == '0'
assert S.largestMultipleOfThree([1, 2]) == '21'
assert S.largestMultipleOfThree([1, 2, 1]) == '21'
assert S.largestMultipleOfThree([1, 2, 1, 3]) == '321'
assert S.largestMultipleOfThree([0, 0, 1, 2, 1, 3]) == '32100'
assert S.largestMultipleOfThree([0, 0]) == '0'
