#!/bin/python

import sys


s = raw_input().strip()
n = long(raw_input().strip())
l = len(s)

print s.count('a') * (n / l) + s[:n % l].count('a')
