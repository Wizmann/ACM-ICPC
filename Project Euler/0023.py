from math import sqrt

def is_abundant(v):
    s = set()
    for i in xrange(1, int(sqrt(v) + 1)):
        if v % i == 0:
            s.add(i)
            s.add(v / i)
    return sum(s) - v > v


SIZE = 28123
s = []
dp = [0 for i in xrange(SIZE + 1)]
for i in xrange(1, SIZE + 1):
    if i % 1000 == 0:
        print i
    if is_abundant(i):
        s.append(i)

for i in s:
    for j in s:
        if i + j <= SIZE:
            dp[i + j] = 1

ans = 0

for i in xrange(1, SIZE + 1):
    if not dp[i]:
        ans += i
print ans
