# -*- coding:utf-8 -*-
class Solution:
    # array 二维列表
    def Find(self, target, array):
        n = len(array)
        m = len(array[0])
        
        y, x = 0, m - 1
        
        while y < n and x >= 0:
            if array[y][x] == target:
                return True
            elif array[y][x] < target:
                y += 1
            else:
                x -= 1
        return False
