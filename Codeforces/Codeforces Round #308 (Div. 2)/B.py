n = int(raw_input())

ans = 0

for i in xrange(1, 12):
    u = (10 ** i) - (10 ** (i - 1))
    if n >= u:
        ans += i * u
        n -= u
    else:
        ans += i * n
        n -= n
        
print ans
