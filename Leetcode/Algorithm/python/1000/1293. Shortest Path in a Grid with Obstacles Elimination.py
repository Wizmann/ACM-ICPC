from collections import deque

INF = 10 ** 10

my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class Solution(object):
    def shortestPath(self, grid, k):
        n = len(grid)
        m = len(grid[0])
        #print n, m
        q = deque()
        q.append((0, 0, 0, 0))
        d = {}
        mini = INF
        while q:
            (y, x, b, step) = q.popleft()
            #print y, x, b, step
            if y == n - 1 and x == m - 1:
                mini = min(mini, step)
                continue
            if step > mini:
                continue
            for i in xrange(4):
                ny = y + my[i]
                nx = x + mx[i]
                
                if ny < 0 or ny >= n or nx < 0 or nx >= m:
                    continue
                bb = b
                if grid[ny][nx] == 1:
                    bb = b + 1
                if bb > k:
                    continue
                    
                key = (ny, nx, bb)
                if key in d:
                    continue
                d[key] = step + 1
                q.append((ny, nx, bb, step + 1))
        return -1 if mini >= INF else mini

