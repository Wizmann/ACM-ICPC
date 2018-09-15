#!/bin/python

import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(board):
    n = len(board)
    m = len(board[0])
    
    for i in xrange(n):
        for j in xrange(n):
            if i - 1 >= 0:
                if board[i - 1][j] ^ board[i][j] == 0:
                    return False
            if j - 1 >= 0:
                if board[i][j - 1] ^ board[i][j] == 0:
                    return False
    return True

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input().strip())

    for t_itr in xrange(t):
        n = int(raw_input().strip())

        board = []

        for _ in xrange(n):
            board.append(map(int, raw_input().rstrip().split()))

        result = "Yes" if solve(board) else "No"

        fptr.write(result + '\n')

    fptr.close()
