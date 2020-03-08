INF = 10 ** 10
N = 100
n, T = map(int, raw_input().split())

stores = []
zs = []
for i in xrange(n):
    a, b = map(int, raw_input().split())
    if a == 0:
        zs.append(b)
    else:
        stores.append((a, b))

def mycmp(s1, s2):
    a1, b1 = s1
    a2, b2 = s2
    v1 = a2 + a2 * b1
    v2 = a1 + a1 * b2
    return cmp(v1, v2)

stores.sort(cmp=mycmp)
stores.append((INF, INF))
zs.sort()

m = len(zs)

for i in xrange(1, m):
    zs[i] += zs[i - 1]

dp = [ [INF for i in xrange(N)] for j in xrange(2) ]
dp[0][0] = 0
res = 0

n = len(stores)

p = 0
for i in xrange(n):
    q = p ^ 1
    dp[q] = [INF for j in xrange(N)]

    a, b = stores[i]
    for j in xrange(N):
        dp[q][j] = min(dp[q][j], dp[p][j])
        if dp[p][j] == -INF:
            continue
        if j + 1 < N:
            t = dp[p][j] + 1
            dp[q][j + 1] = min(dp[q][j + 1], dp[p][j] + 1 + a * t + b)
            if dp[q][j + 1] <= T:
                res = max(res, j + 1)
    for j in xrange(N):
        if dp[q][j] > T:
            continue
        rem = T - dp[q][j] - 1
        l, r = 0, m - 1
        while l <= r:
            mid = (l + r) / 2
            if zs[mid] + mid <= rem:
                res = max(res, j + mid + 1)
                l = mid + 1
            else:
                r = mid - 1
    p = q
print res

