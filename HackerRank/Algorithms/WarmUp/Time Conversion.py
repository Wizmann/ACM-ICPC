#!/bin/python

import sys
import re

def solve(timestr):
    (hh, mm, ss, ampm) = re.match("(\d+)\:(\d+)\:(\d+)(\w+)", timestr).groups()
    (hh, mm, ss) = map(int, (hh, mm, ss))

    if ampm == 'AM' and hh == 12:
        hh = 0
    elif ampm == 'PM' and hh == 12:
        hh = 12
    elif ampm == 'PM':
        hh += 12

    return '%02d:%02d:%02d' % (hh, mm ,ss)
    

if __name__ == '__main__':
    assert solve("12:00:00PM") == "12:00:00"
    assert solve("12:00:00AM") == "00:00:00"
    assert solve("08:21:22PM") == "20:21:22"

    timestr = raw_input().strip()
    print solve(timestr)
