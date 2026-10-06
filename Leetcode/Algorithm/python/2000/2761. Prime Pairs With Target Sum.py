N = 1234567

def _is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

primes = set(filter(_is_prime, range(2, N)))

class Solution(object):
    def findPrimePairs(self, n):
        res = []
        for i in xrange(2, n):
            a = i
            b = n - i
            if a > b:
                break
            if a in primes and b in primes:
                res.append([a, b])
        return res

'''
^^^^TEST^^^^
10
----------------
[[3,7],[5,5]]
$$$$TEST$$$$

^^^^TEST^^^^
2
----------------
[]
$$$$TEST$$$$

'''
