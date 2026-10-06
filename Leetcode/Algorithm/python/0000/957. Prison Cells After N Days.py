class Solution(object):
    def prisonAfterNDays(self, cells, N):
        self.d = {}
        step = 0
        while N:
            key = self.cellsToKey(cells)
            if key in self.d:
                delta = step - self.d[key]
                N %= delta
            if N == 0:
                break
            self.d[key] = step
            cells = self.process(cells)
            N -= 1
            step += 1
        return cells
            
        
    def cellsToKey(self, cells):
        return int(''.join(map(str, cells)))
        
    def process(self, cells):
        n = len(cells)
        p = [0 for i in xrange(n)]
        
        for i in xrange(1, n - 1):
            l, r = cells[i - 1], cells[i + 1]
            p[i] = int(not (l ^ r))
        return p
