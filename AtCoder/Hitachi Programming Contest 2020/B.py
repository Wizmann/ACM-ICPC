INF = 10 ** 10
def solve(As, Bs, Ms):
    mini = min(As) + min(Bs)
    for (a, b, c) in Ms:
        cur = As[a] + Bs[b] - c
        mini = min(mini, cur)
    return mini

a, b, m = map(int, raw_input().split())
As = [INF] + map(int, raw_input().split())
Bs = [INF] + map(int, raw_input().split())
Ms = []
for i in xrange(m):
    (a, b, c) = map(int, raw_input().split())
    Ms.append((a, b, c))
print solve(As, Bs, Ms)

