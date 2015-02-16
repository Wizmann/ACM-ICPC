VOWELS = list('AEIOUY')
N = 500010

ds = [0 for i in xrange(N)]

for i in xrange(1, N):
    ds[i] = ds[i - 1] + 1.0 / i

S = raw_input()
n = len(S)
d = 0
ans = 0

for i, c in enumerate(S):
    d += ds[n - i] - ds[i]
    if c in VOWELS:
        ans += d

print ans
