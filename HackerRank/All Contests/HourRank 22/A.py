#!/bin/python

import sys

def smallestSizeSubsequence(n, A):
    if sum(A) % 2 == 0:
        return 0
    elif len(A) == 1 and A[0] % 2 == 1:
        return -1
    else:
        return 1
    
n = int(raw_input().strip())
A = map(int, raw_input().strip().split(' '))
result = smallestSizeSubsequence(n, A)
print(result)
