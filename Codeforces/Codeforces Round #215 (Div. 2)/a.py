(n, d) = map(int, raw_input().split())
a = map(int, raw_input().split())
m = int(raw_input())

a.sort()

res = 0

if n < m:
    res += sum(a)
    res -= (m - n) * d
else:
    res += sum(a[:m])

print res






