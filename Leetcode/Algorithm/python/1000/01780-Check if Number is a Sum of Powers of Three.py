class Solution(object):
    def checkPowersOfThree(self, n):
        while n:
            if n % 3 == 2:
                return False
            n /= 3
        return True
