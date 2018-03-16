#!/bin/python

import sys
from collections import Counter

def beautifulTriplets(d, arr):
    c = Counter(arr)
    
    keys = sorted(c.keys())
    
    ans = 0
    
    for key in keys:
        x, y = key + d, key + 2 * d
        ans += c[key] * c.get(x, 0) * c.get(y, 0)
    
    return ans

if __name__ == "__main__":
    n, d = raw_input().strip().split(' ')
    n, d = [int(n), int(d)]
    arr = map(int, raw_input().strip().split(' '))
    result = beautifulTriplets(d, arr)
    print result

