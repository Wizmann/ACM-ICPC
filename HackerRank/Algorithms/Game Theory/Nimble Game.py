#!/bin/python

import math
import os
import random
import re
import sys

# Complete the nimbleGame function below.
def nimbleGame(s):
    tot = 0
    for i, cnt in enumerate(s):
        tot ^= (cnt % 2) * i
    return "First" if tot else "Second"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        n = int(raw_input())

        s = map(int, raw_input().rstrip().split())

        result = nimbleGame(s)

        fptr.write(result + '\n')

    fptr.close()
