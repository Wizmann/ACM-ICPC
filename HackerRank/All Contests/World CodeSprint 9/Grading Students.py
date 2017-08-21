#!/bin/python

import sys


n = int(raw_input().strip())
for a0 in xrange(n):
    grade = int(raw_input().strip())
    if grade < 38:
        print grade
    else:
        if (grade + 2) / 5 == grade / 5 + 1:
            grade = (grade + 2) / 5 * 5
        print grade
