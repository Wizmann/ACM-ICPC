INF = 10 ** 10

def solve(x, y):
    if x >= y:
        return x - y

    d = {}
    q = [y]
    d[y] = 0

    mini = y - x

    while q:
        cur = q.pop(0)
        mini = min(mini, d[cur] + abs(cur - x))
        if d[cur] > mini:
            continue
        if cur <= x:
            continue

        if cur % 2 == 0:
            nxt = cur / 2
            if nxt not in d and nxt > 0:
                d[nxt] = d[cur] + 1
                q.append(nxt)
        else:
            for nxt in [cur + 1, cur - 1]:
                if nxt not in d and nxt > 0:
                    d[nxt] = d[cur] + 1
                    q.append(nxt)

    return mini

# assert solve(3, INF) == 0
assert solve(3, 9) == 3
assert solve(7, 11) == 3
assert solve(INF, INF) == 0

(x, y) = map(int, raw_input().split())

print solve(x, y)
