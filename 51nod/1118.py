MOD = (10 ** 9 + 7)

(n, m) = map(int, raw_input().split())

ans = 1
for i in xrange(n - 1):
    ans *= (m + n - 2 - i)
    ans /= (i + 1)

print ans % MOD
