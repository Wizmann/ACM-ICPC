from collections import defaultdict

def getdis(a, b, n, x, y):
    mini = abs(a - b)
    mini = min(mini, abs(a - x) + 1 + abs(b - y))
    mini = min(mini, abs(a - y) + 1 + abs(b - x))
    return mini

def solve(n, x, y):
    dis = [0 for i in xrange(n)]
    for i in xrange(1, n + 1):
        for j in xrange(i + 1, n + 1):
            u = getdis(i, j, n, x, y)
            # print i, j, u
            dis[u] += 1
    return dis[1:]

(n, x, y) = map(int, raw_input().split())

res = solve(n, x, y)
for num in res:
    print num
