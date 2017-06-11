import sys

(n, m) = map(int, raw_input().split())

if n <= 1:
    print 0
    sys.exit(0)

if m == 0:
    print 'Impossible'
    sys.exit(0)
    
ms = map(int, raw_input().split())



ms = sorted(ms)
ans = 0
while n and ms:
    t = ms.pop()
    if not t:
        continue
    ans += 1
    if t >= n:
        n = 0
    else:
        n -= t - 1

if n:
    print 'Impossible'
else:
    print ans
