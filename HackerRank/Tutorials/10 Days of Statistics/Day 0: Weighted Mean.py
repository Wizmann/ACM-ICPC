n = int(raw_input())
ns = map(int, raw_input().split())
ms = map(int, raw_input().split())
print '%.1f' % (1.0 * sum(map(lambda (x, y): x * y, zip(ns, ms))) / sum(ms))
