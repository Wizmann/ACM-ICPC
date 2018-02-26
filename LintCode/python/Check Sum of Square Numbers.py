import math

class Solution:
    """
    @param num: the given number
    @return: whether whether there're two integers
    """
    def checkSumOfSquareNumbers(self, num):
        if num < 0:
            return False
            
        i = 0
        while i * i <= num:
            b = num - i * i
            if b >= 0 and int(math.sqrt(b)) ** 2 == b:
                return True
            i += 1
        return False
