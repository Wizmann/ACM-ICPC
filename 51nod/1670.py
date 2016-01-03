N = 111111
MOD = 1000000007
factors = [1] * N

for i in xrange(1, N):
    factors[i] = (factors[i - 1] * i) % MOD
    
n = int(raw_input())
ns = map(int, raw_input().split())

buckets = [0] * N
presum = [0] * N

for num in ns:
    buckets[num] += 1
    
for i in xrange(0, N):
    presum[i] = buckets[i]
    if i - 1 >= 0:
        presum[i] += presum[i - 1]

ans = 0
pre = 1
step = 0
for i in xrange(n):
    a = presum[i]
    b = presum[n] - presum[i]

    ans += (pre * b * factors[n - i - 1] * step) % MOD
    if a - i <= 0:
        break
        
    t = pre * (a - i)
    pre = (t % MOD)
    
    step += 1
else:
    ans += pre * step
    
print ans % MOD
