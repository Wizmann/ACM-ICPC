n = int(raw_input())

ans = 1.0
for i in xrange(n, 1, -1):
    ans = ans * (i * 2 - 2) / (i * 2 - 1)
print ans
