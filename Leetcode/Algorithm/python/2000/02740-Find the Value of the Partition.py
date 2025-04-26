#!/usr/bin/env python
# -*- coding: utf-8 -*-

INF = 10 ** 100

class Solution(object):
    def findValueOfPartition(self, nums):
        n = len(nums)
        nums.sort()
        mini = INF
        for i in xrange(1, n):
            mini = min(mini, nums[i] - nums[i - 1])
        return mini

'''
^^^^^TEST^^^^
[1,3,2,4]
----------
1
$$$$$TEST$$$$
'''
