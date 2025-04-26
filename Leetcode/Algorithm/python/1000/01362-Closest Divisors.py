# https://leetcode.com/problems/closest-divisors/

from typing import *

INF = 10 ** 10

class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        cur = 1
        target = [num + 1, num + 2]
        maxi = INF
        res = (-1, -1)
        while cur * cur <= num + 2:
            for t in target:
                if t % cur == 0:
                    a, b = cur, t // cur
                    a, b = min(a, b), max(a, b)
                    if abs(a - b) < maxi:
                        res = (a, b)
                        maxi = abs(a - b)
            cur += 1
        return res

S = Solution()
assert(S.closestDivisors(1) == (1, 2))
assert(S.closestDivisors(8) == (3, 3))
assert(S.closestDivisors(999) == (25, 40))
assert(S.closestDivisors(123) == (5, 25))

