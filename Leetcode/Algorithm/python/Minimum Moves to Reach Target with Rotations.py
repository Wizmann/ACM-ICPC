class Solution(object):
    def minimumMoves(self, grid):
        self.n = len(grid)
        self.m = len(grid[0])
        
        mv = [
            ( (0, 1), (0, 1) ), # move right
            ( (1, 0), (1, 0) ), # move down
            ( (0, 0), (1, -1) ), # clockwise
            ( (0, 0), (-1, 1) ), # counterclockwise
        ]
        
        idx = self.to_idx((0, 0), (0, 1))
        q = [ ((0, 0), (0, 1)) ]
        inq = set([idx])
        d = {idx: 0}
        while q:
            (p1, p2) = q.pop(0)
            #print p1, p2
            idx = self.to_idx(p1, p2)
            inq.remove(idx)
            step = d[idx]
            for i, (m1, m2) in enumerate(mv):
                if i == 2:
                    if p1[0] != p2[0]:
                        continue
                    assert p1[0] == p2[0]
                    assert p1[1] == p2[1] - 1
                    (ny, nx) = p1
                    ny += 1
                    if not (0 <= ny < self.n and 0 <= nx < self.m and grid[ny][nx] == 0):
                        continue
                    if ny >= self.n:
                        continue

                    (ny, nx) = p2
                    ny += 1
                    if not (0 <= ny < self.n and 0 <= nx < self.m and grid[ny][nx] == 0):
                        continue
                    if ny >= self.n:
                        continue

                if i == 3:
                    if p1[1] != p2[1]:
                        continue
                    assert p1[1] == p2[1]
                    assert p1[0] == p2[0] - 1
                    (ny, nx) = p1
                    nx += 1
                    if not (0 <= ny < self.n and 0 <= nx < self.m and grid[ny][nx] == 0):
                        continue
                    if nx >= self.m:
                        continue

                    (ny, nx) = p2
                    nx += 1
                    if not (0 <= ny < self.n and 0 <= nx < self.m and grid[ny][nx] == 0):
                        continue
                    if nx >= self.m:
                        continue

                dy, dx = m1
                pp1 = (p1[0] + dy, p1[1] + dx)
                if not (0 <= pp1[0] < self.n and 0 <= pp1[1] < self.m and grid[pp1[0]][pp1[1]] == 0):
                    continue
                
                dy, dx = m2
                pp2 = (p2[0] + dy, p2[1] + dx)
                
                if not (0 <= pp2[0] < self.n and 0 <= pp2[1] < self.m and grid[pp2[0]][pp2[1]] == 0):
                    continue
                    
                idx = self.to_idx(pp1, pp2)
                if idx in inq:
                    continue
                if idx in d:
                    continue
                d[idx] = step + 1
                q.append((pp1, pp2))
                inq.add(idx)
        idx = self.to_idx((self.n - 1, self.n - 2), (self.n - 1, self.n - 1))
        return d.get(idx, -1)
    
    def to_idx(self, p1, p2):
        res = 0
        (y, x) = p1
        res += y * self.m + x + 1
        res *= 100007
        (y, x) = p2
        res += y * self.m + x + 1
        return res

