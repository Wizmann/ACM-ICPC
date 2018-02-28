class Solution:
    """
    @param generator: Generating set of rules.
    @param startSymbol: Start symbol.
    @param symbolString: Symbol string.
    @return: Return true if the symbol string can be generated, otherwise return false.
    """
    def canBeGenerated(self, generator, startSymbol, symbolString):
        self.symbol = symbolString
        self.d = []
        
        for g in generator:
            l, r = map(lambda s: s.strip(), g.split("->"))
            self.d.append((l, r))
        
        return self.dfs(startSymbol)
        
    def dfs(self, cur):
        # print cur
        if cur == self.symbol:
            return True
            
        if len(cur) > len(self.symbol):
            return False
            
        if cur == cur.lower():
            return False
            
        for (k, v) in self.d:
            if k in cur:
                next = cur[:]
                next = next.replace(k, v, 1)
                if self.dfs(next):
                    return True
        return False
