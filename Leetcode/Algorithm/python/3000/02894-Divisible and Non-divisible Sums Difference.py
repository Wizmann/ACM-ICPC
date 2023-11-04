class Solution(object):
    def differenceOfSums(self, n, m):
        num1 = sum(filter(lambda x: x % m != 0, range(1, n + 1)))
        num2 = sum(filter(lambda x: x % m == 0, range(1, n + 1)))
        return num1 - num2
