n = int(raw_input())

fs = [ 0.0 ]
for i in xrange(n):
    fs.append(float(input()))
a = [0 for i in xrange(n + 1)]

for i in xrange(1, n + 1):
    a[i] = fs[i] * (a[i - 1] + 1)

b = [0 for i in xrange(n + 1)]
for i in xrange(1, n + 1):
    b[i] = fs[i] * (b[i - 1] + 2 * a[i - 1] + 1)

res = 0
c = [0 for i in xrange(n + 1)]
for i in xrange(1, n + 1):
    c[i] = fs[i] * (3 * b[i - 1] + 3 * a[i - 1] + 1) 
    res += c[i]

print '%.1f' % res

'''
^^^TEST^^^
3 
0.5 
0.5 
0.5
---
6.0
$$$TEST$$$
'''

