from collections import defaultdict

INF = 10 ** 10

(n, m) = map(int, raw_input().split())

g = defaultdict(list)
for i in xrange(m):
    a, b, c = map(int, raw_input().split())
    g[a].append((b, c))
    g[b].append((a, c))
s, t = map(int, raw_input().split())
dis = [INF for i in xrange(n + 1)]
visit = set([s])
q = [s]
dis[s] = 0
while q:
    cur = q.pop(0)
    visit.remove(cur)
    for (nxt, cost) in g[cur]:
        if dis[cur] + cost < dis[nxt]:
            dis[nxt] = dis[cur] + cost
            if nxt not in visit:
                q.append(nxt)
                visit.add(nxt)
print dis[t]
