n = int(raw_input())
ans = []
factors = set()

for i in xrange(2, n):
    if i * i > n:
        break
    if n % i == 0:
        factors.add(i)
        factors.add(n / i)
        
if (n - 1) % 2 == 0:
    if (n - 1) / 2 > 0:
        ans.append((n - 1) / 2)
        
for factor in factors:
    x = n / factor
    if factor % 2 == 1 and x > factor / 2:
        ans.append(x - (factor / 2))
    if (x - 1) % 2 == 0:
        u = (x - 1) / 2
        if u > factor - 1:
            ans.append(u - factor + 1)

if ans:
    print '\n'.join(map(str, sorted(ans)))
else:
    print 'No Solution'
