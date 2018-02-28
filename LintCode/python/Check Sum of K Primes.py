class Solution:
    """
    @param n: an int
    @param k: an int
    @return: if N can be expressed in the form of sum of K primes, return true; otherwise, return false.
    """
    def isSumOfKPrimes(self, n, k):
        if k == 1:
            return self.is_prime(n)
        if k == 2:
            return (n >= 4 and n % 2 == 0) or self.is_prime(n - 2)
        if n % 2 == 1:
            n -= (k - 3) * 2
            k = 3
            return n > 5
        else:
            n -= (k - 2) * 2
            k = 2
            return n >= 4
    
    def is_prime(self, num):
        if num < 2:
            return False
        i = 2
        while i * i <= num:
            if num % i == 0:
                return False
            i += 1
        return True
