#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution(object):
    def longestString(self, x, y, z):
        self.dp = {}
        self.dfs(x, y, z, 'X')
        # print self.dp
        return max(self.dp.values())

    def dfs(self, x, y, z, pre):
        key = (x, y, z, pre)
        if key in self.dp:
            return self.dp[key]

        res = 0
        if x and pre != 'A':
            res = max(res, self.dfs(x - 1, y, z, 'A') + 2)
        if y and pre != 'B':
            res = max(res, self.dfs(x, y - 1, z, 'B') + 2)
        if z and pre != 'A':
            res = max(res, self.dfs(x, y, z - 1, 'B') + 2)

        self.dp[key] = res
        return res

'''
^^^^TEST^^^^
1
1
0
------------
4
$$$$$$$TEST$$$$

^^^^TEST^^^^
2
5
1
------------
12
$$$$$$$TEST$$$$

^^^^TEST^^^^
3
2
2
------------
14
$$$$$$$TEST$$$$

'''
