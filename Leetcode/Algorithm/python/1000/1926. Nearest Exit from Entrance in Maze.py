INF = 10 ** 10

class Solution(object):
    def nearestExit(self, maze, entrance):
        q = []
        n = len(maze)
        m = len(maze[0])
        sy, sx = entrance
        dis = [[INF for i in xrange(m)] for j in xrange(n)]
        q.append((sy, sx))
        dis[sy][sx] = 0
        while q:
            y, x = q.pop(0)
            for (my, mx) in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
                ny = y + my
                nx = x + mx
                if 0 <= ny < n and 0 <= nx < m and maze[ny][nx] == '.':
                    if dis[y][x] + 1 < dis[ny][nx]:
                        dis[ny][nx] = dis[y][x] + 1
                        q.append((ny, nx))
        ans = INF
        # print dis
        for i in xrange(m):
            if (0, i) != (sy, sx):
                ans = min(ans, dis[0][i])
            if (n - 1, i) != (sy, sx):
                ans = min(ans, dis[n - 1][i])
        for i in xrange(n):
            if (i, 0) != (sy, sx):
                ans = min(ans, dis[i][0])
            if (i, m - 1) != (sy, sx):
                ans = min(ans, dis[i][m - 1])
        if ans >= INF:
            ans = -1
        return ans
