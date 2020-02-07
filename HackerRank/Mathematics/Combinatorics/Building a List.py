#!/bin/python3

# https://www.hackerrank.com/challenges/building-a-list/problem

import os
import sys

class Solution(object):
    def __init__(self, s):
        s = s.strip()
        self.s = list(sorted(s))
        self.buf = []
        self.res = []

    def solve(self):
        self.dfs('^', 0)
        return sorted(self.res)

    def dfs(self, pre, cur):
        if cur == len(self.s):
            if self.buf:
                self.res.append(''.join(self.buf))
            return
        if self.s[cur] == pre:
            self.dfs(pre, cur + 1)
            return
        self.buf.append(self.s[cur])
        self.dfs(self.s[cur], cur + 1)
        self.buf.pop()
        self.dfs(pre, cur + 1) 

def solve(s):
    S = Solution(s)
    return S.solve()
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        s = input()

        result = solve(s)

        fptr.write('\n'.join(result))
        fptr.write('\n')

    fptr.close()
