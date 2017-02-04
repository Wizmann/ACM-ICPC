import re

n = int(raw_input())
for i in xrange(n):
    s = raw_input().strip()
    if re.match("^[A-Z]{5}\d{4}[A-Z]$", s):
        print 'YES'
    else:
        print 'NO'
