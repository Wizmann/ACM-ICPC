#!/bin/python

import math
import os
import random
import re
import sys

MAXI = 1111

# Complete the powerSum function below.
def powerSum(X, N, pre=0):
    res = 0
    if not X:
        return 1
    
    for j in xrange(pre + 1, X + 1):
        if j ** N > X:
            break
        Y = X - (j ** N)
        res += powerSum(Y, N, j)
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    X = int(raw_input())

    N = int(raw_input())

    result = powerSum(X, N)

    fptr.write(str(result) + '\n')

    fptr.close()
