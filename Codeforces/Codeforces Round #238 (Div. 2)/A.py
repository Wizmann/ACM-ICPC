# Result: 6124292    Mar 23, 2014 2:36:53 PM    Wizmann  A - Gravity Flip    Python 2   Accepted    62 ms   0 KB
MAX_HEIGHT = 128

n = int(raw_input())
boxes = map(int, raw_input().split())
height = [0 for i in xrange(MAX_HEIGHT)]
res = [0 for i in xrange(n)]

for i in xrange(MAX_HEIGHT):
    idx = 0
    for box in boxes:
        if box > i:
            res[idx] += 1
            idx += 1
print ' '.join(map(str, res[::-1]))
