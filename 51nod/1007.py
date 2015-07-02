SIZE = 12345

dp = [0 for i in xrange(SIZE)]
dp[0] = 1

n = int(raw_input())
ns = [int(raw_input()) for i in xrange(n)]

for u in ns:
    for i in xrange(SIZE - 1, -1, -1):
        if dp[i] and i + u < SIZE:
            dp[i + u] = 1
            
s = sum(ns)

ans = 0xdeadbeef

for i in xrange(SIZE):
    if dp[i]:
        ans = min(ans, abs(i - (s - i)))
        
print ans
