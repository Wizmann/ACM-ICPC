import math

m = (math.sqrt(5) + 1) / 2

n = int(raw_input())

for i in xrange(n):
    (a, b) = map(int, raw_input().split())
    (a, b) = min(a, b), max(a, b)
    delta = b - a
    if a == int(m * delta):
        print 'B'
    else:
        print 'A'
