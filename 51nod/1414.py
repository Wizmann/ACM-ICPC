n = int(raw_input())
ns = map(int, raw_input().split())

ans = sum(ns)

i = 2
while i <= n:
    if n % i or n / i < 3:
        i += 1
        continue
    for j in xrange(i):
        ans = max(ans, sum(ns[j::i]))
    i += 1
print ans
