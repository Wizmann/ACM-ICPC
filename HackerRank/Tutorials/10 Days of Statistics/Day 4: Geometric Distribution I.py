(a, b) = map(int, raw_input().split())
n = int(raw_input())

p = 1.0 * a / b
q = 1 - p

print '%.3f' % ((q ** 4) * (p))
