def is_prime(x):
    if x == 1:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    
    n = 3
    while n * n <= x:
        if x % n == 0:
            return False
        n += 2
    return True

class Solution(object):
    def diagonalPrime(self, nums):
        n = len(nums)
        maxi = 0
        for i in xrange(n):
            if is_prime(nums[i][i]):
                maxi = max(maxi, nums[i][i])
            if is_prime(nums[i][n - i - 1]):
                maxi = max(maxi, nums[i][n - i - 1])
        return maxi
            
