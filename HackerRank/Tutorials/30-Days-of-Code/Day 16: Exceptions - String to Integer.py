#!/bin/python

import sys


S = raw_input().strip()

try:
    print int(S)
except:
    print 'Bad String'
