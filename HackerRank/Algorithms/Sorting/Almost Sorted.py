import sys

INF = 0x3f3f3f3f

def check(ns):
    dd = ns[:-1]
    return dd == sorted(dd)

n = int(raw_input())
ns = map(int, raw_input().split()) + [-INF]

seq = []

pre = -1
pre_idx = 0
for i, num in enumerate(ns):
    if num < pre:
        seq.append((pre_idx, i - 1))
        pre_idx = i
    pre = num
    

a, b = seq[0][1], seq[-1][0]

ns[a], ns[b] = ns[b], ns[a]
if check(ns):
    print 'yes'
    print 'swap', a + 1, b + 1
    sys.exit(0)

ns[a], ns[b] = ns[b], ns[a]
ns[a: b + 1] = ns[a: b + 1][::-1]
if check(ns):
    print 'yes'
    print 'reverse', a + 1, b + 1
    sys.exit(0)

print 'no'
        