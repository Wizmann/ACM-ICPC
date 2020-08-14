#!/bin/python

import math
import os
import random
import re
import sys
from copy import deepcopy

INF = 10 ** 10

magicSquare = [
    [8, 1, 6],
    [3, 5, 7],
    [4, 9, 2]
]

def mirror(square):
    square = deepcopy(square)
    for i in xrange(len(square)):
        square[i] = square[i][::-1]
    return square

def T(square):
    square = deepcopy(square)
    n = len(square)
    m = len(square[0])

    for i in xrange(n):
        for j in xrange(i, m):
            square[i][j], square[j][i] = square[j][i], square[i][j]
    return square

def rotate(square):
    return mirror(T(square))

def getMagicSquares():
    square = deepcopy(magicSquare)
    for i in xrange(4):
        yield square
        yield mirror(square)
        square = rotate(square)

# Complete the formingMagicSquare function below.
def formingMagicSquare(s):
    mini = INF

    for square in getMagicSquares():
        tot = 0
        # print square
        for i in xrange(3):
            for j in xrange(3):
                tot += abs(s[i][j] - square[i][j])
        mini = min(mini, tot)
    return mini

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = []

    for _ in xrange(3):
        s.append(map(int, raw_input().rstrip().split()))

    result = formingMagicSquare(s)

    fptr.write(str(result) + '\n')

    fptr.close()
