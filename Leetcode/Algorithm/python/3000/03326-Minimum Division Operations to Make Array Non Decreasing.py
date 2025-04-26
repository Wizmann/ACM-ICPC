def _is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

primes = filter(_is_prime, range(2, 1111))

class Solution(object):
    def minOperations(self, nums):
        n = len(nums)
        pre = nums[-1]
        cnt = 0
        for i in xrange(n - 2, -1, -1):
            if nums[i] > pre:
                for prime in primes:
                    if nums[i] % prime == 0:
                        div = nums[i] / prime
                        nums[i] /= div
                        cnt += 1
                        if nums[i] > pre:
                            return -1
                        break
                else:
                    return -1
            pre = nums[i]
        return cnt
