import sys

sys.stdin = open('b.txt')

n = int(raw_input())
ns = map(int, raw_input().split())

for i in xrange(1, n):
    ns[i] += ns[i - 1]

qn = int(raw_input())
qs = map(int, raw_input().split())

for q in qs:
    l, r = 0, n - 1
    while l <= r:
        m = (l + r) >> 1
        if ns[m] >= q:
            r = m - 1
        else:
            l = m + 1
    print l + 1
