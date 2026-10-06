from collections import defaultdict

class Solution(object):
    def gridIllumination(self, N, lamps, queries):
        self.n = N
        d = defaultdict(set)
        for (y, x) in lamps:
            idxs = self.get_index(y, x)
            for idx in idxs:
                d[idx].add((y, x))
        res = []
        for (y, x) in queries:
            idxs = self.get_index(y, x)
            flag = 0
            for idx in idxs:
                if idx in d and len(d[idx]) > 0:
                    flag = 1
                    break
            res.append(flag)
            for (dy, dx) in [(dy, dx) for dy in [-1, 0, 1] for dx in [-1, 0, 1]]:
                if dy == 0 and dx == 0:
                    continue
                ny, nx = y + dy, x + dx
                if y < 0 or y >= self.n or x < 0 or x >= self.n:
                    continue
                idxs = self.get_index(ny, nx)
                for idx in idxs:
                    if idx in d and (ny, nx) in d[idx]:
                        d[idx].remove((ny, nx))
        return res            
                
    def get_index(self, y, x):
        idx0 = (0, y - min(y, x), x - min(y, x))
        idx1 = (1, 0, x)
        idx2 = (2, y, 0)
        idx3 = (3, y + min(self.n - y, x), x - min(self.n - y, x))
        
        return [idx0, idx1, idx2, idx3]
        
