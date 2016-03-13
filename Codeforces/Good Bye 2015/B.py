import sys

N = 64
years = []

for i in xrange(2, N + 1):
    u = (1 << i) - 1
    for j in xrange(i - 1):
        v = u ^ (1 << j)
        years.append(v)
        
a, b = map(int, raw_input().split())

ans = 0
for year in years:
    if a <= year <= b:
        ans += 1
        
print ans
