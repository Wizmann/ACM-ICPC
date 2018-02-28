#!/bin/python

import sys
import string

s_len = int(raw_input().strip())
s = raw_input().strip()

ans = 0
for c1 in string.ascii_lowercase:
    for c2 in string.ascii_lowercase:
        if c1 == c2:
            continue
        ss = filter(lambda c: c in [c1, c2], s)
        if len(ss) < 2 or c1 not in ss or c2 not in ss:
            continue
        x = ss[::2]
        y = ss[1::2]
        if len(set(x)) == 1 and len(set(y)) == 1:
            ans = max(ans, len(ss))
print ans

