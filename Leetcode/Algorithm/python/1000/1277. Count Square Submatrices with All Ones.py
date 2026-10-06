from collections import defaultdict

class Solution(object):
    def countSquares(self, matrix):
        n = len(matrix)
        m = len(matrix[0])
        
        for i in xrange(1, n):
            for j in xrange(1, m):
                if matrix[i][j]:
                    matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1
        return sum([sum(line) for line in matrix])
