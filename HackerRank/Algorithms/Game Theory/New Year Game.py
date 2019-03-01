#!/bin/python

import math
import os
import random
import re
import sys
from collections import Counter

dp = {}

class Solution(object):
    def __init__(self, counter):
        self.status = (counter[0], counter[1], counter[2])
    
    def solve(self):
        return self.dfs(self.status[0] % 2, self.status[1] % 2, self.status[2] % 2, 0, 0)

    def dfs(self, p0, p1, p2, delta, turn):
        delta = (delta % 3 + 3) % 3
        assert p0 >= 0 and p1 >= 0 and p2 >= 0
        if p1 + p2 == 0:
            if turn == 1:
                return delta % 3 == 0
            else:
                return delta % 3 != 0

        key = (p0, p1, p2, delta, turn)
        if key in dp:
            return dp[key]

        flag = False
        g = -1 if turn else 1
        if not flag and p0 > 0:
            flag |= not self.dfs(p0 - 1, p1, p2, delta, not turn)
        if not flag and p1 > 0:
            flag |= not self.dfs(p0, p1 - 1, p2, delta + 1 * g, not turn)
        if not flag and p2 > 0:
            flag |= not self.dfs(p0, p1, p2 - 1, delta + 2 * g, not turn)

        dp[key] = flag
        return flag

if __name__ == '__main__':
    T = int(raw_input())

    for T_itr in xrange(T):
        n = int(raw_input())

        ns = map(lambda x: x % 3, map(int, raw_input().rstrip().split()))
        c = Counter(ns)

        print 'Balsa' if Solution(c).solve() else 'Koca'

        
