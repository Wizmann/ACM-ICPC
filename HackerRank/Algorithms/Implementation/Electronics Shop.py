#!/bin/python

from __future__ import print_function

import os
import sys

#
# Complete the getMoneySpent function below.
#
def getMoneySpent(keyboards, drives, b):
    maxi = -1
    for k in keyboards:
        for d in drives:
            if k + d <= b:
                maxi = max(maxi, k + d)
    return maxi

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    bnm = raw_input().split()

    b = int(bnm[0])

    n = int(bnm[1])

    m = int(bnm[2])

    keyboards = map(int, raw_input().rstrip().split())

    drives = map(int, raw_input().rstrip().split())

    #
    # The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
    #

    moneySpent = getMoneySpent(keyboards, drives, b)

    fptr.write(str(moneySpent) + '\n')

    fptr.close()
