T = int(raw_input())

for case_ in xrange(T):
    (x1, y1, x2, y2) = map(int, raw_input().split())
    x3 = x2 + (x2 - x1)
    y3 = y2 + (y2 - y1)
    print x3, y3
