class Solution(object):
    def sumOfTheDigitsOfHarshadNumber(self, x):
        y = sum(map(int, str(x)))
        if x % y == 0:
            return y
        else:
            return -1
