from collections import defaultdict

class Solution(object):
    def isNStraightHand(self, hand, W):
        d = defaultdict(int)
        for h in hand:
            d[h] += 1
            
        flag = True
        while d and flag:
            u = min(d.keys())
            for i in xrange(u, u + W):
                if i in d:
                    d[i] -= 1
                    if d[i] == 0:
                        del d[i]
                else:
                    flag = False
                    break
        
        return flag
