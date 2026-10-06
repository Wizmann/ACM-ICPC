# https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

from typing import *

N = 555
MOD = 10 ** 9 + 7

inv2 = pow(2, MOD - 2, MOD)

class Solution:
    def countOrders(self, n: int) -> int:
        tot = 1
        for i in range(n):
            u = (n - i) * 2
            tot = tot * (u * (u - 1) % MOD * inv2 % MOD) % MOD
        return tot

S = Solution()
assert(S.countOrders(1) == 1)
assert(S.countOrders(2) == 6)
assert(S.countOrders(3) == 90)
