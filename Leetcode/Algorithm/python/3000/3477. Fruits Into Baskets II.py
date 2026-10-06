class Solution(object):
    def numOfUnplacedFruits(self, fruits, baskets):
        cnt = 0
        m = len(baskets)
        for fruit in fruits:
            for i in xrange(m):
                if fruit <= baskets[i]:
                    baskets[i] = -1
                    break
            else:
                cnt += 1
        return cnt
