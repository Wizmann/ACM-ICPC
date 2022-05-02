my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class Solution(object):
    def maximumMinutes(self, grid):
        fires = []

        n = len(grid)
        m = len(grid[0])

        fire = []
        for i in xrange(n):
            for j in xrange(m):
                if grid[i][j] == 1:
                    fire.append((i, j))

        fires.append(fire[:])

        visited = set()
        for (y, x) in fire:
            visited.add((y, x))

        for i in xrange(1, n * m + 1):
            fire = []
            for (y, x) in fires[i - 1]:
                for (dy, dx) in zip(my, mx):
                    ny = y + dy
                    nx = x + dx
                    if ny < 0 or ny >= n or nx < 0 or nx >= m:
                        continue
                    if grid[ny][nx] != 0:
                        continue
                    if (ny, nx) in visited:
                        continue
                    fire.append((ny, nx))
                    visited.add((ny, nx))
            fires.append(fire[:])

        l, r = 0, n * m + 1
        while l <= r:
            mid = (l + r) / 2

            if self.check(mid, grid, fires):
                l = mid + 1
            else:
                r = mid - 1
        if r >= n * m + 1:
            r = 10 ** 9
        return r

    def check(self, cur, grid, fires):
        n = len(grid)
        m = len(grid[0])
        onfire = set()
        visited = set()
        for i in xrange(cur + 1):
            if cur < len(fires):
                for fire in fires[i]:
                    onfire.add(fire)

        q = [ [(0, 0)], [] ]
        ptr = 0

        print cur

        flag = False
        while q[ptr]:
            qtr = ptr ^ 1
            q[qtr] = []


            for (y, x) in q[ptr]:
                if (y, x) in onfire:
                    continue
                for dy, dx in zip(my, mx):
                    ny = y + dy
                    nx = x + dx

                    if ny < 0 or ny >= n or nx < 0 or nx >= m:
                        continue
                    if grid[ny][nx] != 0:
                        continue
                    if (ny, nx) in onfire:
                        continue
                    if (ny, nx) in visited:
                        continue

                    q[qtr].append((ny, nx))
                    visited.add((ny, nx))
            cur += 1
            if cur < len(fires):
                for fire in fires[cur]:
                    onfire.add(fire)
            if (n - 1, m - 1) in visited:
                return True
            # print cur, onfire
            # print q[qtr]

            ptr = qtr
        
        return False


'''
^^^^TEST^^^^
[[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
-------
3
$$$TEST$$$

^^^^TEST^^^^
[[0,0,0,0],[0,1,2,0],[0,2,0,0]]
-------
-1
$$$TEST$$$

^^^^TEST^^^^
[[0,0,0],[2,2,0],[1,2,0]]
-------
1000000000
$$$TEST$$$

^^^^TEST^^^
[[0,2,0,0,1],[0,2,0,2,2],[0,2,0,0,0],[0,0,2,2,0],[0,0,0,0,0]]
-------
0
$$$TEST$$$


'''
