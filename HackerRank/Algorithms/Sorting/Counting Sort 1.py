N = 100

n = int(raw_input())
ns = map(int, raw_input().split())
ms = [0 for i in xrange(N)]

for i in ns:
    ms[i] += 1

print ' '.join(map(str, ms))
