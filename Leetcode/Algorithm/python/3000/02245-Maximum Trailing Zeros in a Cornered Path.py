class Solution(object):
    def maxTrailingZeros(self, grid):
        n = len(grid)
        m = len(grid[0])
        
        dpx = [ [[0, 0] for j in xrange(m)] for i in xrange(n) ]
        dpy = [ [[0, 0] for j in xrange(m)] for i in xrange(n) ]
        
        for i in xrange(n):
            for j in xrange(m):
                cur = grid[i][j]
                cnt_2 = 0
                while cur % 2 == 0:
                    cnt_2 += 1
                    cur /= 2
                cnt_5 = 0
                while cur % 5 == 0:
                    cnt_5 += 1
                    cur /= 5
                grid[i][j] = [cnt_2, cnt_5]
        
        for i in xrange(n):
            for j in xrange(m - 1, -1, -1):
                cnt_2, cnt_5 = grid[i][j]
                
                if j + 1 < m:
                    dpx[i][j] = dpx[i][j + 1][:]
                dpx[i][j][0] += cnt_2
                dpx[i][j][1] += cnt_5
            
        for j in xrange(m):
            for i in xrange(n - 1, -1, -1):
                cnt_2, cnt_5 = grid[i][j]

                if i + 1 < n:
                    dpy[i][j] = dpy[i + 1][j][:]
                dpy[i][j][0] += cnt_2
                dpy[i][j][1] += cnt_5
        res = 0
        for i in xrange(n):
            for j in xrange(m):
                cnt_2, cnt_5 = grid[i][j]

                ys = [
                    dpy[i][j],
                    [
                        dpy[0][j][0] - (0 if i + 1 >= n else dpy[i + 1][j][0]),
                        dpy[0][j][1] - (0 if i + 1 >= n else dpy[i + 1][j][1])
                    ]
                ]
                
                xs = [
                    dpx[i][j],
                    [
                        dpx[i][0][0] - (0 if j + 1 >= m else dpx[i][j + 1][0]),
                        dpx[i][0][1] - (0 if j + 1 >= m else dpx[i][j + 1][1])
                    ]
                ]
                
                for (y1, y2) in ys:
                    for (x1, x2) in xs:
                        res = max(res, min(y1 + x1 - cnt_2, y2 + x2 - cnt_5))
        return res

                
