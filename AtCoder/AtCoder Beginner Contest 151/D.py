h, w = map(int, raw_input().split())
maze = [list(raw_input()) for i in xrange(h)]

INF = 10 ** 10
my = [-1, 0, 1, 0]
mx = [0, -1, 0, 1]
def bfs(sy, sx):
    q = [(sy, sx)]
    dp = [ [INF for j in xrange(w)] for i in xrange(h) ]
    dp[sy][sx] = 0
    while q:
        (y, x) = q.pop(0)
        for (dy, dx) in zip(my, mx):
            ny = y + dy
            nx = x + dx
            if ny < 0 or nx < 0 or ny >= h or nx >= w:
                continue
            if maze[ny][nx] == '#':
                continue
            if dp[ny][nx] != INF:
                continue
            dp[ny][nx] = dp[y][x] + 1
            q.append((ny, nx))
    res = 0
    for i in xrange(h):
        for j in xrange(w):
            if maze[i][j] != '#':
                res = max(res, dp[i][j])
    return res

res = 0
for sy in xrange(h):
    for sx in xrange(w):
        if maze[sy][sx] == '#':
            continue
        res = max(res, bfs(sy, sx))
print res
