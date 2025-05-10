#python2
#coding=utf-8

import sys
import io

if sys.version_info[0] == 3:
    raw_input = input
    xrange = range
    map_ = map
    sorted_ = sorted
    def map(*args, **kwargs):
        return list(map_(*args, **kwargs))
    def sorted(*args, **kwargs):
        return list(sorted_(*args, **kwargs))

T = int(raw_input())

for case_ in xrange(T):
    a, b, c = map(int, raw_input().split())
    ave = (a + b + c) / 3
    if ave * 3 == (a + b + c):
        if a <= ave and b <= ave:
            print 'YES'
        else:
            print 'NO'
    else:
        print 'NO'

'''
^^^^^TEST^^^^
4
3 5 10
12 20 30
3 5 7
1 5 6
----------
YES
NO
YES
NO
$$$$$TEST$$$$
'''


