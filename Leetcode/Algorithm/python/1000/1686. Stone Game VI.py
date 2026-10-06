class Solution(object):
    def stoneGameVI(self, aliceValues, bobValues):
        n = len(aliceValues)
        diff = [0 for i in xrange(n)]
        for i in xrange(n):
            diff[i] = (aliceValues[i] + bobValues[i], i)
        diff.sort(reverse=True)
        a, b = 0, 0
        for i in xrange(n):
            if i % 2 == 0:
                a += aliceValues[diff[i][1]]
            else:
                b += bobValues[diff[i][1]]
                
        if a > b:
            return 1
        elif a < b:
            return -1
        return 0
