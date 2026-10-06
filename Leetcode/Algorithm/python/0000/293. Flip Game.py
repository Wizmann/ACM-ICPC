class Solution(object):
    def generatePossibleNextMoves(self, s):
        if not s:
            return []
        
        n = len(s)
        cur = self.to_int(s)
        
        res = set()

        for i in xrange(n - 1):
            mask = 0b11 << i
            if (cur & mask) == mask:
                next = cur ^ mask
                if next not in res:
                    res.add(next)
        return map(lambda u: self.to_string(n, u), res)  

    def to_int(self, s):
        return int(s.replace("+", "1").replace("-", "0"), 2)
    
    def to_string(self, n, u):
        res = ''
        for i in xrange(n):
            if u & 1:
                res = "+" + res
            else:
                res = "-" + res
            u >>= 1
        return res
        
