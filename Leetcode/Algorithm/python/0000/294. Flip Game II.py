class Solution(object):
    def canWin(self, s):
        if not s:
            return False
        self.d = {}
        return self.doCanWin(len(s), self.to_int(s))
    
    def doCanWin(self, n, cur):
        if cur in self.d:
            return self.d[cur]
        
        nexts = self.generatePossibleNextMoves(n, cur)
        for next in nexts:
            if not self.doCanWin(n, next):
                self.d[cur] = True
                return True
        self.d[cur] = False
        return False
        
    def generatePossibleNextMoves(self, n, cur):
        res = set()
        for i in xrange(n - 1):
            mask = 0b11 << i
            if (cur & mask) == mask:
                next = cur ^ mask
                if next not in res:
                    res.add(next)
        return res

    def to_int(self, s):
        return int(s.replace("+", "1").replace("-", "0"), 2)
