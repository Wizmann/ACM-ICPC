def A(a, b):
    res = 1
    for i in xrange(a):
        res *= b - i
    return res

class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        if n == 0:
            return 1
        return A(n, 10) - A(n - 1, 9) + self.countNumbersWithUniqueDigits(n - 1)
        
