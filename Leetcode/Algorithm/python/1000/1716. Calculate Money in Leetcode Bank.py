class Solution(object):
    def totalMoney(self, n):
        w = (n + 6) / 7
        base = 1
        res = 0
        for i in xrange(w):
            u = min(7, n)
            n -= u
            res += (base + base + u - 1)  * u / 2
            
            base += 1
        return res
            
