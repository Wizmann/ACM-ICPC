import sys
n = int(raw_input())

def query(a, b, c, d):
    print '? %d %d %d %d' % (a, b, c, d)
    sys.stdout.flush()
    res = int(raw_input())
    assert res != -1
    return res

## ROW

l, r = 1, n
while l <= r:
    m = (l + r) / 2
    res = query(l, m, 1, n)
    if res < (m - l + 1):
        r = m - 1
    else:
        l = m + 1

R = r + 1

## COL
l, r = 1, n
while l <= r:
    m = (l + r) / 2
    res = query(1, n, l, m)
    if res < (m - l + 1):
        r = m - 1
    else:
        l = m + 1
C = r + 1

print '! %d %d' % (R, C)
