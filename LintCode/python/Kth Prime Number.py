class Solution:
    """
    @param n: the number
    @return: the rank of the number
    """
    def kthPrime(self, n):
        primes = [2]
        cur = 3
        while primes[-1] < n:
            is_prime = True
            for prime in primes:
                if cur % prime == 0:
                    is_prime = False
                    break
                
                if prime * prime > cur:
                    break
            if is_prime:
                primes.append(cur)
                
            cur += 2
        return len(primes)
                
