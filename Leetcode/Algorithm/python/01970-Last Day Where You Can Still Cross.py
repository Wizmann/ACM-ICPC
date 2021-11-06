from collections import deque

mvs = [ (-1, 0), (0, 1), (1, 0), (0, -1) ]
INF = 10 ** 10

class Solution(object):
    def latestDayToCross(self, row, col, cells):
        n = len(cells)
        l, r = 0, n
        while l <= r:
            m = (l + r) / 2
            self.matrix = [ [0 for j in xrange(col)] for i in xrange(row) ]
            for i in xrange(m):
                y, x = cells[i]
                y -= 1
                x -= 1
                self.matrix[y][x] = 1
            if self.bfs():
                l = m + 1
            else:
                r = m - 1
        return r
    
    def bfs(self):
        q = deque()
        n = len(self.matrix)
        m = len(self.matrix[0])
        visited = set()
        for i in xrange(m):
            if self.matrix[0][i] == 0:
                q.append((0, i))
                visited.add((0, i))
            
        maxi = 0
        
        while q:
            (y, x) = q.popleft()
            for (dy, dx) in mvs:
                ny = y + dy
                nx = x + dx
                if 0 <= ny < n and 0 <= nx < m and self.matrix[ny][nx] == 0:
                    maxi = max(maxi, ny)
                    if ((ny, nx) not in visited):
                        q.append((ny, nx))
                        visited.add((ny, nx))
                if maxi == n - 1:
                    return True
        return False
        
                
