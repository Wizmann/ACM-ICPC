# -*- coding:utf-8 -*-
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        n = len(rotateArray)
        if n == 0:
            return 0
        l, r = 0, n - 1
        while l <= r:
            m = (l + r) / 2
            a, b, c = rotateArray[l], rotateArray[m], rotateArray[r]
            if b >= a and b >= c:
                l = m + 1
            elif b <= a and b <= c:
                r = m
            elif a < c:
                r = m - 1
            else:
                l = m + 1
        return rotateArray[r]
