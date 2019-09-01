"""
DP.

We mark the calculation procedure as F(nums).

It's easy to know there are 2 status of nums[0] for all the subsets, present and not present.

It means if nums[0] is present, the summary of those subsets (2 ** nums[0]) * F(nums[1:]). If not, we have 1 * F(nums[1:]).

The dp formula is: F(nums) = ((2 ** nums[0]) + 1) * F(nums[1:]).

According to that, we can use a DP array to do the calculation from 0 to n - 1. Or we can use only 1 temp variables to do that from n - 1 to 0.
"""

#!/bin/python

from __future__ import print_function

import os
import sys

MOD = (10 ** 9) + 7

# Complete the solve function below.
def solve(nums):
    n = len(nums)
    tot = 1
    for num in nums:
        tot = tot * (pow(2, num, MOD) + 1) % MOD
    return (tot + MOD - 1) % MOD

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a_count = int(raw_input())

    a = map(long, raw_input().rstrip().split())

    result = solve(a)

    fptr.write(str(result) + '\n')

    fptr.close()
