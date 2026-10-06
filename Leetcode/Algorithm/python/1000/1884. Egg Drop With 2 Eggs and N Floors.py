INF = 10 ** 10

class Solution(object):
    def twoEggDrop(self, n):
        tot = 0
        for i in xrange(1, INF):
            tot += i
            if tot >= n:
                return i
        
