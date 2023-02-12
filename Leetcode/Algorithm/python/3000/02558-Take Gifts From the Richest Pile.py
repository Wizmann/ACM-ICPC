import math

class Solution(object):
    def pickGifts(self, gifts, k):
        for i in xrange(k):
            gifts.sort()
            gifts[-1] = int(math.sqrt(gifts[-1]))
        return sum(gifts)
