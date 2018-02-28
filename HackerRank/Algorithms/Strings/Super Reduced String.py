#!/bin/python

import sys

def super_reduced_string(s):
    ss = []
    for c in s:
        if ss and ss[-1] == c:
            ss.pop()
        else:
            ss.append(c)
    if not ss:
        return 'Empty String'
    else:
        return ''.join(ss)

s = raw_input().strip()
result = super_reduced_string(s)
print(result)
