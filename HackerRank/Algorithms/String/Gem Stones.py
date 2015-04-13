import string

n = int(raw_input())

res = set(string.ascii_lowercase)
for i in xrange(n):
    u = set(raw_input())
    res &= u
print len(res)