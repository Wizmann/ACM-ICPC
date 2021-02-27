INF = 10 ** 10

my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class Solution(object):
    def minimumEffortPath(self, heights):
        n = len(heights)
        m = len(heights[0])
        dp = [[INF for j in xrange(m)] for i in xrange(n)]
        dp[0][0] = 0
        q = [(0, 0)]
        inq = set([(0, 0)])
        
        while q:
            y, x = q.pop(0)
            inq.remove((y, x))
            
            for (dy, dx) in zip(my, mx):
                ny = y + dy
                nx = x + dx
                
                if ny < 0 or ny >= n or nx < 0 or nx >= m:
                    continue
                    
                cost = max(dp[y][x], abs(heights[y][x] - heights[ny][nx]))
                
                if cost < dp[ny][nx]:
                    dp[ny][nx] = cost
                    if (ny, nx) not in inq:
                        q.append((ny, nx))
                        inq.add((ny, nx))
        # print dp
        return dp[n - 1][m - 1]
            
