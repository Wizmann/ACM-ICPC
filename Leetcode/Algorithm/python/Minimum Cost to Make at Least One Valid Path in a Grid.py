from typing import *

INF = 10 ** 10

mx = [1, -1, 0, 0]
my = [0, 0, 1, -1]

class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        self.n = len(grid)
        self.m = len(grid[0])

        self.dis = [[INF for j in range(self.m)] for i in range(self.n)]

        self.dis[0][0] = 0
        self.q = [(0, 0)]
        self.visit = set([(0, 0)])

        while self.q:
            cur = self.q.pop(0)
            self.visit.remove(cur)

            y, x = cur
            for i in range(4):
                ny = y + my[i]
                nx = x + mx[i]
                nc = self.dis[y][x] + (0 if i == grid[y][x] - 1 else 1)

                if 0 <= ny < self.n and 0 <= nx < self.m:
                    if nc < self.dis[ny][nx]:
                        self.dis[ny][nx] = nc
                        if (ny, nx) not in self.visit:
                            self.visit.add((ny, nx))
                            self.q.append((ny, nx))
        res = self.dis[self.n - 1][self.m - 1]
        return res

S = Solution()

assert(S.minCost([[1,1,3],[3,2,2],[1,1,4]]) == 0)
assert(S.minCost([[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]) == 3)
assert(S.minCost([[1,2],[4,3]]) == 1)
assert(S.minCost([[4]]) == 0)
