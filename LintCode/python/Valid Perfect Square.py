import math

class Solution:
    """
    @param num: a positive integer
    @return: if num is a perfect square else False
    """
    def isPerfectSquare(self, num):
        return int(math.sqrt(num)) ** 2 == num
