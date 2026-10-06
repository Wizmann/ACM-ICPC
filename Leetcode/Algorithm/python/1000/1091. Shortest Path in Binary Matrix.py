from collections import deque

INF = 10 ** 10

my = [-1, -1, -1, 0, 0, 1, 1, 1]
mx = [-1, 0, 1, -1, 1, -1, 0, 1]

class Solution(object):
    def shortestPathBinaryMatrix(self, grid):
        n = len(grid)
        m = len(grid[0])
        dp = [ [ INF for i in xrange(m) ] for j in xrange(n) ]
        if grid[0][0] == 1:
            return -1
        dp[0][0] = 0
        q = deque([(0, 0)])
        while q:
            y, x = q[0]
            q.popleft()
            
            for (dy, dx) in zip(my, mx):
                ny = y + dy
                nx = x + dx
                if ny < 0 or nx < 0 or ny >= n or nx >= m:
                    continue
                if grid[ny][nx] == 1:
                    continue
                if dp[ny][nx] < INF:
                    continue
                dp[ny][nx] = dp[y][x] + 1
                q.append((ny, nx))
        res = dp[n - 1][m - 1] + 1
        if res >= INF:
            return -1
        return res
