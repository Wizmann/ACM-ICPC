# -*- coding:utf-8 -*-
class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        mv = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        (y, x) = (0, 0)
        n = len(matrix)
        m = len(matrix[0])
        res = []
        dir = 0
        while y >= 0 and y < n and x >= 0 and x < m and matrix[y][x] != -1:
            res.append(matrix[y][x])
            matrix[y][x] = -1
            ny, nx = y + mv[dir][1], x + mv[dir][0]
            if ny < 0 or ny >= n or nx < 0 or nx >= m or matrix[ny][nx] == -1:
                dir = (dir + 1) % 4
                ny, nx = y + mv[dir][1], x + mv[dir][0]
            y, x = ny, nx
        return res
