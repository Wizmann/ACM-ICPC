
def solve(xb, yb):
    # xc >= xb
    # (xb + yc) = |yc - yb|
    if (xb + yb) % 2 == 0:
        yc = (xb + yb) / 2
        xc = (xb + yb) / 2 - yc
        if xc >= xb and xc >= 0:
            return xc, yc

    # xc <= xb
    # yc >= yb
    yc = yb
    xc2 = xb + yb - 2 * yc
    if xc2 % 2 == 0:
        xc = xc2 / 2
        if xc <= xb and xc >= 0:
            return xc2 / 2, yc

    # xc <= xb
    # yc <= yb
    if (xb + yb) % 2 == 0:
        for i in xrange(0, xb + 1):
            for j in xrange(0, yb + 1):
                xc = i
                yc = j
                if (2 * D(0, 0, xc, yc) == D(0, 0, xb, yb) and 
                        2 * D(xb, yb, xc, yc) == D(0, 0, xb, yb)):
                    return xc, yc

    return -1, -1

def D(xa, ya, xb, yb):
    return abs(xb - xa) + abs(ya - yb)


T = int(raw_input())
for case_ in xrange(T):
    (xb, yb) = map(int, raw_input().split())
    (xc, yc) = solve(xb, yb)

    # print xb, yb, xc, yc
    # print D(0, 0, xc, yc), D(0, 0, xb, yb)
    # print D(xb, yb, xc, yc), D(0, 0, xb, yb)
    # print '---'
    if xc != -1 and yc != -1:
        assert 2 * D(0, 0, xc, yc) == D(0, 0, xb, yb)
        assert 2 * D(xb, yb, xc, yc) == D(0, 0, xb, yb)

    print xc, yc

'''
^^^TEST^^^
10
49 3
2 50
13 0
0 41
42 0
0 36
13 37
42 16
42 13
0 0
------
23 3
1 25
-1 -1
-1 -1
21 0
0 18
13 12
25 4
-1 -1
0 0
$$$TEST$$$
'''

