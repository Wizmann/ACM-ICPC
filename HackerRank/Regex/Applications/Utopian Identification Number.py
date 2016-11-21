import re

n = int(raw_input())
for i in xrange(n):
    s = raw_input()
    if re.search("^[a-z]{0,3}[\d]{2,8}[A-Z]{3,}", s):
        print 'VALID'
    else:
        print 'INVALID'
