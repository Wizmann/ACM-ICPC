#!/bin/python

import sys

def do_solve(grade):
    if grade < 38:
        return grade
    
    u = (grade / 5 + 1) * 5
    if u - grade < 3:
        return min(100, u)
    else:
        return grade

def solve(grades):
    return map(do_solve, grades)


n = int(raw_input().strip())
grades = []
grades_i = 0
for grades_i in xrange(n):
    grades_t = int(raw_input().strip())
    grades.append(grades_t)
result = solve(grades)
print "\n".join(map(str, result))
