class Solution(object):
    def countPrimeSetBits(self, L, R):
        ans = 0
        for i in xrange(L, R + 1):
            u = '{:b}'.format(i).count('1')
            ans += 1 if self.is_prime(u) else 0
        return ans
    
    def is_prime(self, u):
        return u in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
