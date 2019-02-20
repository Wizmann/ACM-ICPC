import copy

class Solution(object):
    def orangesRotting(self, grid):
        n = len(grid)
        m = len(grid[0])
        step = 0
        while True:
            cnt = 0
            newgrid = copy.deepcopy(grid)
            for i in xrange(n):
                for j in xrange(m):
                    if grid[i][j] != 1:
                        continue
                    for (my, mx) in [(-1, 0), (0, 1), (0, -1), (1, 0)]:
                        ny = i + my
                        nx = j + mx
                        
                        if ny >= n or ny < 0 or nx >= m or nx < 0:
                            continue
                            
                        if grid[ny][nx] == 2:
                            newgrid[i][j] = 2
                            cnt += 1
            if cnt:
                grid = newgrid
                step += 1
            else:
                break
            
            
        ok = 0
        for i in xrange(n):
            for j in xrange(m):
                if grid[i][j] == 1:
                    ok += 1
        if ok:
            return -1
        else:
            return step
