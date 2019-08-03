from copy import deepcopy

class Solution(object):
    def largest1BorderedSquare(self, grid):
        n = len(grid)
        m = len(grid[0])

        gridx = deepcopy(grid)
        for i in xrange(n):
            for j in xrange(1, m):
                gridx[i][j] += gridx[i][j - 1]
                
        gridy = deepcopy(grid)
        for j in xrange(m):
            for i in xrange(1, n):
                gridy[i][j] += gridy[i - 1][j]
        print gridx, gridy, grid      
        maxi = 0
        for i in xrange(n):
            for j in xrange(m):
                for k in xrange(max(m, n), -1, -1):
                    if k < maxi:
                        break
                    if i + k - 1 >= n:
                        continue
                    if j + k - 1 >= m:
                        continue
                    a = gridx[i][j + k - 1] - gridx[i][j] + grid[i][j]
                    b = gridx[i + k - 1][j + k - 1] - gridx[i + k - 1][j] + grid[i + k - 1][j]
                    c = gridy[i + k - 1][j] - gridy[i][j] + grid[i][j]
                    d = gridy[i + k - 1][j + k - 1] - gridy[i][j + k - 1] + grid[i][j + k - 1]
                    #print (i, j), a, b, c, d
                    if min(a, b, c, d) >= k:
                        maxi = max(maxi, k)
        return maxi ** 2
                    
                
        
