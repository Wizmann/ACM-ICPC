import sys

(n, x) = map(int, raw_input().split())
ns = filter(
    lambda y: x | y == x,
    [int(raw_input()) for i in xrange(n)]
)

ans = 0xdeadbeef
for i in xrange(66):
    if not (x & (1 << i)):
        continue
    ans = min(ans, len(filter(lambda y: y & (1 << i), ns)))

print ans
