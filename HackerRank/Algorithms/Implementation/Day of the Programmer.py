#!/bin/python

import sys
import datetime

days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

year = int(raw_input())

if year == 1918:
    days[1] = 15
if year < 1918 and year % 4 == 0:
    days[1] = 29
elif (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
    days[1] = 29

cur = 255
for i in xrange(12):
    if cur > days[i]:
        cur -= days[i]
    else:
        print '%02d.%02d.%d' % (cur + 1, i + 1, year)
        break
