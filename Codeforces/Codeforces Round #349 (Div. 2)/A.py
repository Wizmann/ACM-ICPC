#!/usr/bin/python

import math
(d, h, v, e) = map(float, raw_input().split())

ee = e * (d / 2) * (d / 2) * math.pi

if ee >= v:
    print 'NO'
else:
    print 'YES'
    print h * (d / 2) * (d / 2) * math.pi / (v - ee)