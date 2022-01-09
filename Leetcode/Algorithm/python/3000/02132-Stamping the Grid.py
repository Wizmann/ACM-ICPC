from copy import deepcopy
class Solution(object):
    def possibleToStamp(self, grid, stampHeight, stampWidth):
        origin = deepcopy(grid)
        n = len(grid)
        m = len(grid[0])

        for j in xrange(m):
            for i in xrange(1, n):
                grid[i][j] += grid[i - 1][j]

        for i in xrange(n):
            for j in xrange(1, m):
                grid[i][j] += grid[i][j - 1]

        fills = [ [0 for j in xrange(m)] for i in xrange(n) ]

        for i in xrange(stampHeight - 1, n):
            for j in xrange(stampWidth - 1, m):
                if self.range_sum(grid, i - stampHeight + 1, j - stampWidth + 1, i, j) == 0:
                    fills[i][j] = 1

        for j in xrange(m):
            for i in xrange(1, n):
                fills[i][j] += fills[i - 1][j]

        for i in xrange(n):
            for j in xrange(1, m):
                fills[i][j] += fills[i][j - 1]

        for i in xrange(n):
            for j in xrange(m):
                fill = False
                if self.range_sum(fills, i, j, min(n - 1, i + stampHeight - 1), min(m - 1, j + stampWidth - 1)):
                    fill = True

                if origin[i][j] == 0 and not fill:
                    return False

                if origin[i][j] == 1 and fill:
                    assert False
                    return False
        return True

    def range_sum(self, grid, y1, x1, y2, x2):
        tot = grid[y2][x2]
        if y1 - 1 >= 0:
            tot -= grid[y1 - 1][x2]
        if x1 - 1 >= 0:
            tot -= grid[y2][x1 - 1]
        if y1 - 1 >= 0 and x1 - 1 >= 0:
            tot += grid[y1 - 1][x1 - 1]
        return tot

'''
^^^TEST^^^
[[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]]
4
3
-------
true
$$$TEST$$$

^^^TEST^^^
[[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]]
2
2
------
false
$$$TEST$$$
'''

