#!/bin/python

import math
import os
import random
import re
import sys

# Complete the pokerNim function below.
def pokerNim(k, c):
    return 'First' if reduce(lambda x, y: x ^ y, c) else 'Second'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        nk = raw_input().split()

        n = int(nk[0])

        k = int(nk[1])

        c = map(int, raw_input().rstrip().split())

        result = pokerNim(k, c)

        fptr.write(result + '\n')

    fptr.close()
