# -*- coding:utf-8 -*-
class Solution:
    def reOrderArray(self, array):
        n = len(array)
        for i in xrange(n):
            if array[i] % 2 == 0:
                continue
            for j in xrange(i - 1, -1, -1):
                if array[j] % 2 == 1:
                    break
                array[j], array[j + 1] = array[j + 1], array[j]
        return array
