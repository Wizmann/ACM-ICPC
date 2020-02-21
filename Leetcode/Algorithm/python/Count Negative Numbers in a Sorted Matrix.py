# https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        
        x = m - 1
        
        tot = 0
        for i in range(n):
            while x >= 0 and grid[i][x] < 0:
                x -= 1
            #print(m, x, m - x - 1)
            tot += m - x - 1
        return tot
