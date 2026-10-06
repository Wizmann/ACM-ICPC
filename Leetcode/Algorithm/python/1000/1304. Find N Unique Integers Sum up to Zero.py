class Solution(object):
    def sumZero(self, n):
        if n % 2 == 0:
            return range(1, n / 2 + 1) + range(-n / 2, 0)
        else:
            return range(n / 2 + 1) + range(-n / 2 + 1, 0)
