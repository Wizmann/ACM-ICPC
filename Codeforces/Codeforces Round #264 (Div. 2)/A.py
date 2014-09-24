(n, s) = map(int, raw_input().split())

ans = -1
for (x, y) in [map(int, raw_input().split()) for i in xrange(n)]:
    if x + y / 100. <= s:
        ans = max(ans, (100 - y) % 100)

print ans