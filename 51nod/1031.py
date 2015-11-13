MOD = (10 ** 9) + 7

n = int(raw_input())

a, b = 1, 1

for i in xrange(2, n + 1):
    c = a + b
    a, b = b % MOD, c % MOD

print b
