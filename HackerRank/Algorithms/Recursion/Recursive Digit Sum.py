#!/bin/python

import sys

def digitSum(n, k):
    u = sum(map(int, str(n))) * k % 9
    return u or 9

if __name__ == "__main__":
    n, k = raw_input().strip().split(' ')
    n, k = [str(n), int(k)]
    result = digitSum(n, k)
    print result

