import sys

d = {}
for i in xrange(10000):
    s = ''.join(sorted(str(i ** 3)))
    d[s] = d.get(s, [])
    d[s].append(i ** 3)
    if len(d[s]) == 5:
        print min(d[s])
        break
