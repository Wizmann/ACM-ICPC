class Solution:
    def sumOfPrimesInRange(self, n):
        r = int(str(n)[::-1])
        lo, hi = min(n, r), max(n, r)

        ans = 0
        for x in range(lo, hi + 1):
            if self.is_prime(x):
                ans += x
        return ans

    def is_prime(self, x):
        if x < 2:
            return False

        d = 2
        while d * d <= x:
            if x % d == 0:
                return False
            d += 1
        return True

"""
^^^test^^^
13
---
132
$$$test$$$

^^^test^^^
10
---
17
$$$test$$$

^^^test^^^
8
---
0
$$$test$$$

^^^test^^^
1
---
0
$$$test$$$
"""
