class Solution(object):
    def countSubmatrices(self, grid, k):
        n = len(grid)
        m = len(grid[0])

        get = lambda y, x: 0 if x < 0 or y < 0 else grid[y][x]

        cnt = 0
        for i in xrange(n):
            for j in xrange(m):
                grid[i][j] = grid[i][j] + get(i - 1, j) + get(i, j - 1) - get(i - 1, j - 1)
                if grid[i][j] <= k:
                    cnt += 1
                else:
                    break
        return cnt
