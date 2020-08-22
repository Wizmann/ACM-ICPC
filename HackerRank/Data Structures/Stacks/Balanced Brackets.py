#!/bin/python

import math
import os
import random
import re
import sys

# Complete the isBalanced function below.
def isBalanced(s):
    st = []
    for c in s:
        if c in '({[':
            st.append(c)
        else:
            if not st:
                return False
            if st[-1] + c not in ['()', '{}', '[]']:
                return False
            st.pop()
    return not st

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        s = raw_input()

        result = 'YES' if isBalanced(s) else 'NO'

        fptr.write(result + '\n')

    fptr.close()
