def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

INF = 10 ** 10

class Solution(object):
    def minimumLines(self, stockPrices):
        stockPrices.sort()
        n = len(stockPrices)
        st = set()
        pre = (INF, INF)
        cnt = 0
        for i in xrange(1, n):
            x1, y1 = stockPrices[i - 1]
            x2, y2 = stockPrices[i]
            
            k = self.getK(y1 - y2, x1 - x2)
            # print (x1, y1), (x2, y2), k
            if k != pre:
                cnt += 1
            pre = k
        return cnt
    
    def getK(self, dy, dx):
        if dy == 0:
            return (0, 1)
        if dx == 0:
            return (1, 0)
        
        s = 1 if dy * dx > 0 else -1
        dy = abs(dy)
        dx = abs(dx)
        g = gcd(dy, dx)
        
        return (s * dx / g, dy / g)
