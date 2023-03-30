def _is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

primes = sorted([0] + filter(_is_prime, range(2, 1111)))

class Solution(object):
    def primeSubOperation(self, nums):
        pre = 0
        p = 0
        for num in nums:
            u = num - pre
            l, r = 0, len(primes) - 1
            while l <= r:
                m = (l + r) / 2
                if primes[m] >= u:
                    r = m - 1
                else:
                    l = m + 1
            num -= primes[r]
            if num <= 0:
                return False
            pre = num
        return True
