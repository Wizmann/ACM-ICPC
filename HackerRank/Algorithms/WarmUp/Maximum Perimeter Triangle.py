def compare(t1, t2):
    if t1[2] != t2[2]:
        return 1 if t1[2] > t2[2] else 0
    else:
        return 1 if t1[0] > t2[0] else 0
    
n = int(raw_input())
ns = map(int, raw_input().split())

ns.sort()

ans = (-1, -1, -1)
for i in xrange(n):
    for j in xrange(i + 1, n):
        for k in xrange(j + 1, n):
            a, b, c = ns[i], ns[j], ns[k]
            if a + b <= c:
                continue
            if compare((a, b, c), ans):
                ans = (a, b, c)
                
if ans == (-1, -1, -1):
    print -1
else:
    print ' '.join(map(str, ans))
