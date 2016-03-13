class Solution(object):
    def isPowerOfThree(self, n):
        return n > 0 and (3 ** 233) % n == 0
		