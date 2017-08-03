#!/bin/python

import sys

INF = 10 ** 10

def getRecord(s):
    maxi, mini = s[0], s[0]
    res1, res2 = 0, 0
    for item in s:
        if item > maxi:
            res1 += 1
            maxi = item
        if item < mini:
            res2 += 1
            mini = item
    return [res1, res2]

n = int(raw_input().strip())
s = map(int, raw_input().strip().split(' '))
result = getRecord(s)
print " ".join(map(str, result))
