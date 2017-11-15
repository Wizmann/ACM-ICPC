#!/bin/python

import sys
import re

def minimumNumber(n, password):
    eles = [ 
        "[0-9]",
        "[a-z]",
        "[A-Z]",
        "[!@#$%^&*\(\)\-\+]"
    ]
    m = 0
    for ele in eles:
        if not re.findall(ele, password):
            m += 1
    return max(6 - len(password), m)

if __name__ == "__main__":
    n = int(raw_input().strip())
    password = raw_input().strip()
    answer = minimumNumber(n, password)
    print answer
