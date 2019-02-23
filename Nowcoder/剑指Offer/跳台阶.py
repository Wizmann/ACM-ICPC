# -*- coding:utf-8 -*-
class Solution:
    def jumpFloor(self, number):
        if number <= 1:
            return 1
        a, b = 1, 1
        for i in xrange(2, number + 1):
            a, b = b, a + b
        return b
