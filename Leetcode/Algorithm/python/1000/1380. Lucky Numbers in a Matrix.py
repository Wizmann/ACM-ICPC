# https://leetcode.com/problems/lucky-numbers-in-a-matrix/

class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        n = len(matrix)
        if n == 0:
            return 
        m = len(matrix[0])
        rowmin = [min([matrix[i][j] for j in range(m)]) for i in range(n)]
        colmax = [max([matrix[i][j] for i in range(n)]) for j in range(m)]
        
        res = []
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == rowmin[i] == colmax[j]:
                    res.append(matrix[i][j])
        return res
