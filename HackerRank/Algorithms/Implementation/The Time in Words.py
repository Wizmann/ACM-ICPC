#!/bin/python

import sys


h = int(raw_input().strip())
m = int(raw_input().strip())

nn = [
    'zero',
    'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten',
    'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'ninteen', 'twenty',
    'twenty one', 'twenty two', 'twenty three', 'twenty four', 'twenty five', 'twenty six', 'twenty seven', 'twenty eight', 'twenty nine'
]

if m in [0, 15, 30, 45]:
    if m == 0:
        print "%s o' clock" % nn[h]
    elif m == 15:
        print 'quarter past %s' % nn[h]
    elif m == 30:
        print "half past %s" % nn[h]
    else:
        print "quarter to %s" % nn[h + 1]
elif m < 30:
    print "%s minute%s past %s" % (nn[m], 's' if m > 1 else '', nn[h])
else:
    x = 60 - m
    print "%s minute%s to %s" % (nn[x], 's' if x > 1 else '', nn[h + 1])
