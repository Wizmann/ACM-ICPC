INF = 10 ** 10

class Solution(object):
    def isSelfCrossing(self, xs):
        n = len(xs)
        for i in xrange(n):
            if i - 3 >= 0:
                dy = xs[i - 3] - xs[i - 1]
                dx = xs[i] - xs[i - 2]
                
                if dy >= 0 and dx >= 0:
                    print i, 1
                    return True
                
            if i - 4 >= 0:
                dy = xs[i] + xs[i - 4] - xs[i - 2]
                dx = xs[i - 1] - xs[i - 3]
                
                if dy >= 0 and dx == 0:
                    print i, 2
                    return True
            
            if i - 5 >= 0:
                dy = xs[i - 1] + xs[i - 5] - xs[i - 3]
                dx1 = xs[i - 2] - xs[i - 4]
                dx2 = xs[i - 2] - xs[i] - xs[i - 4]
                
                if 0 <= dy <= xs[i - 5] and dx1 >= 0 and dx2 <= 0:
                    print i, 3
                    return True
        return False
