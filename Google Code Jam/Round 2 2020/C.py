#pypy
from collections import defaultdict

T = int(raw_input())

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

INF = 10 ** 100

def getk(p1, p2):
    dx = p1[0] - p2[0]
    dy = p1[1] - p2[1]
    if dx == 0 and dy == 0:
        return (0, 0)
    elif dx == 0:
        return (0, 1) if dy > 0 else (0, -1)
    elif dy == 0:
        return (1, 0) if dx > 0 else (-1, 0)
    else:
        sx = 1 if dx > 0 else -1
        sy = 1 if dy > 0 else -1
        dx = abs(dx)
        dy = abs(dy)
        g = gcd(dx, dy)
        return (sx * dx / g, sy * dy / g)

def dfs1(cur, g, visited):
    if cur in visited:
        return 0
    cnt = 1
    visited.add(cur)
    for nxt in g[cur]:
        cnt += dfs1(nxt, g, visited)
    return cnt


for case_ in xrange(T):
    n = int(raw_input())
    ps = []
    for i in xrange(n):
        (x, y) = map(int, raw_input().split())
        ps.append((x, y))

    d = defaultdict(list)
    for i in xrange(n):
        for j in xrange(n):
            k = getk(ps[i], ps[j])
            d[k].append((i, j))

    ans = 1
    for key, value in d.items():
        g = defaultdict(list)
        for (a, b) in value:
            g[a].append(b)
            g[b].append(a)
        visited = set()
        ns = []
        for i in xrange(n):
            if i in visited:
                continue
            cnt = dfs1(i, g, visited)
            ns.append(cnt)
        ones = filter(lambda x: x == 1, ns)
        evens = filter(lambda x: x > 1 and x % 2 == 0, ns)
        odds = filter(lambda x: x > 1 and x % 2 == 1, ns)

        if len(odds) % 2 == 0:
            ans = max(ans, sum(evens) + sum(odds) + min(2, len(ones)))
        else:
            ans = max(ans, sum(evens) + sum(odds) + min(1, len(ones)))
    print 'Case #%d: %d' % (case_ + 1, ans)



'''
^^^TEST^^^
5
2
0 0
5 5
3
0 0
5 5
5 0
5
0 0
5 5
5 0
3 2
2 4
7
0 0
1 1
2 1
3 1
8 2
11 2
14 2
1
-1000000000 1000000000
----
Case #1: 2
Case #2: 3
Case #3: 4
Case #4: 7
Case #5: 1
$$$TEST$$$

'''
