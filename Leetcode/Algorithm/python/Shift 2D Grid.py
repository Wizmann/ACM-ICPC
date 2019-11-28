def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

class Solution(object):
    def shiftGrid(self, grid, k):
        n = len(grid)
        m = len(grid[0])
        k %= n * m
        g = gcd(k, n * m)
        
        for i in xrange(g):
            idx = i
            cur = idx
            cy, cx = cur / m, cur % m
            curv = grid[cy][cx]
            while True:
                nxt = (cur + k) % (n * m)
                ny, nx = nxt / m, nxt % m
                grid[ny][nx], curv = curv, grid[ny][nx]
                cur = nxt
                if cur == idx:
                    break
        return grid
                
                
        
