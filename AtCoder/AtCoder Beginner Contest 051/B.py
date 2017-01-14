k, s = map(int, raw_input().split())
ans = 0
for x in xrange(k + 1):
    for y in xrange(k + 1):
        z = s - x - y
        if z > k or z < 0:
            continue
        ans += 1
print ans
