#!/bin/python

import math
import os
import random
import re
import sys

# Complete the climbingLeaderboard function below.
def climbingLeaderboard(scores, alice):
    scores = sorted(set(scores), reverse=True)
    d = {}
    p = 0
    for value in sorted(alice, reverse=True):
        while p < len(scores) and value < scores[p]:
            p += 1
        d[value] = p + 1
    return [d[v] for v in alice]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    scores_count = int(raw_input())

    scores = map(int, raw_input().rstrip().split())

    alice_count = int(raw_input())

    alice = map(int, raw_input().rstrip().split())

    result = climbingLeaderboard(scores, alice)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
