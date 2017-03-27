INF = 10 ** 10

n = int(raw_input())
ns = map(int, raw_input().split())
pre = INF

ans = []
for i in xrange(n - 1, -1, -1):
    if ns[i] > pre:
        ans = ns[:i + 1]
        break
    else:
        pre = ns[i]

if not ans:
    ans = [ns[0]]
    
print ' '.join(map(str, ans))
