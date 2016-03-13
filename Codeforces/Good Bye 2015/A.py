import sys
import datetime

(a, b, c) = raw_input().split()

d = datetime.date(2016, 1, 1)
a = int(a)

ans = 0

for i in xrange(366):
    dd, ww = d.day, d.weekday() + 1

    if c == 'month' and a == dd:
        ans += 1

    if c == 'week' and a == ww:
        ans += 1

    d += datetime.timedelta(1)

print ans
