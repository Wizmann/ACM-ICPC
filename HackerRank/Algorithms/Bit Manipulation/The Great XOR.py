#!/bin/python

import math
import os
import random
import re
import sys

# Complete the theGreatXor function below.
def theGreatXor(x):
    xs = map(int, '{:b}'.format(x))
    n = len(xs)
    res = 0
    for i, bit in enumerate(xs):
        if bit == 0:
            m = n - i
            res += 1 << (m - 1)
    return res


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(raw_input())

    for q_itr in xrange(q):
        x = int(raw_input())

        result = theGreatXor(x)

        fptr.write(str(result) + '\n')

    fptr.close()
