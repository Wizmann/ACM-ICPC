class Solution(object):
    def reverseSubmatrix(self, grid, y, x, k):
        for j in xrange(x, x + k):
            l, r = y, y + k - 1
            while l < r:
                # print l, r, j
                grid[l][j], grid[r][j] = grid[r][j], grid[l][j]
                l += 1
                r -= 1
        return grid
        
