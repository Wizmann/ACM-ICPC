class Solution(object):
    def sumOfMultiples(self, n):
        tot = 0
        for i in xrange(1, n + 1):
            if i % 3 == 0 or i % 5 == 0 or i % 7 == 0:
                tot += i
        return tot
