#!/bin/python

from __future__ import print_function

import os
import sys


#
# Complete the highestValuePalindrome function below.
#
def highestValuePalindrome(s, n, k):
    s = map(int, list(str(s)))
    t = s[:]

    p, q = 0, n - 1
    while p < q:
        if s[p] != s[q]:
            s[p] = s[q] = max(s[p], s[q])
            k -= 1
        p += 1
        q -= 1
        
    if k < 0:
        return "-1"

    p, q = 0, n - 1
    while p <= q and k:
        assert s[p] == s[q]
        if s[p] == 9:
            p += 1
            q -= 1
            continue
        if p != q:
            m = (s[p] == t[p]) + (s[q] == t[q])
        else:
            m = 1

        if k < m:
            p += 1
            q -= 1
            continue
        s[p] = s[q] = 9
        k -= m
        p += 1
        q -= 1
    return ''.join(map(str, s))

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    nk = raw_input().split()

    n = int(nk[0])

    k = int(nk[1])

    s = raw_input()

    result = highestValuePalindrome(s, n, k)

    f.write(result + '\n')

    f.close()
