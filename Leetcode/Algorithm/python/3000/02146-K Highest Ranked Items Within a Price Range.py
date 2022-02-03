INF = 10 ** 10
my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class Solution(object):
    def highestRankedKItems(self, grid, pricing, start, k):
        self.n = len(grid)
        self.m = len(grid[0])
        n = self.n
        m = self.m

        self.dis = [ [INF for j in xrange(m)] for i in xrange(n) ]
        self.bfs(grid, start)

        items = []
        lower, upper = pricing
        for i in xrange(n):
            for j in xrange(m):
                if lower <= grid[i][j] <= upper and self.dis[i][j] < INF:
                    items.append(
                        (self.dis[i][j],# dis
                         grid[i][j],    # price
                         i,             # row
                         j))            # column
        items.sort()
        return map(lambda (_, __, i, j): (i, j), items[:k])

    def bfs(self, grid, start):
        sy, sx = start
        q = [(sy, sx)]
        self.dis[sy][sx] = 0
        while q:
            y, x = q.pop(0)

            for i in xrange(4):
                ny = y + my[i]
                nx = x + mx[i]

                if 0 <= ny < self.n and 0 <= nx < self.m:
                    if grid[ny][nx] and self.dis[ny][nx] == INF:
                        self.dis[ny][nx] = self.dis[y][x] + 1
                        q.append((ny, nx))



'''
^^^^^TEST^^^
[[1,2,0,1],[1,3,0,1],[0,2,5,1]]
[2,5]
[0,0]
3
-------
[[0,1],[1,1],[2,1]]
$$$$$TEST$$$$$

^^^^^TEST^^^^
[[1,2,0,1],[1,3,3,1],[0,2,5,1]]
[2,3]
[2,3]
2
----------
[[2,1],[1,2]]
$$$TEST$$$

^^^^TEST^^^
[[1,1,1],[0,0,1],[2,3,4]]
[2,3]
[0,0]
3
----------
[[2,1],[2,0]]
$$$$TEST$$$$$

'''

