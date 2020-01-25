from collections import defaultdict

d = defaultdict(int)
n = int(raw_input())
i = 2
while i * i <= n:
    while n % i == 0:
        d[i] += 1
        n /= i
    if i == 2:
        i += 1
    else:
        i += 2

if n != 1:
    d[n] += 1

#print d
res = 1
for (key, value) in d.items():
    res *= (key - 1) * (key ** (value - 1))
print res
