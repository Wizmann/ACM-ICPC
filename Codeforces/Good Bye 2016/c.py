INF = 10 ** 10

def calc(cur, results):
    for (score, div) in results:
        cur -= score
        if div == 1:
            if cur < 1900:
                return -1 # too low
        if div == 2:
            if cur >= 1900:
                return 1 # too high
    return 0

def solve(results):
    results = results[::-1]

    l, r = -INF, INF

    while l <= r:
        m = (l + r) >> 1
        if calc(m, results) == 1: # high
            r = m - 1
        else:
            l = m + 1
    res = r
    if calc(res, results) == 0:
        if res >= INF:
            return "Infinity"
        else:
            return res
    else:
        return "Impossible"

assert solve([
(-7 , 1),
(5  , 2),
(8  , 2)
]) == 1907

assert solve([
(57 , 1),
(22 , 2),
]) == 'Impossible'

assert solve([
(-5 , 1)
]) == 'Infinity'

assert solve([
(27  , 2),
(13  , 1),
(-50 , 1),
(8   , 2)
]) == 1897

if __name__ == '__main__':
    n = int(raw_input())
    results = []
    for i in xrange(n):
        (c, d) = map(int, raw_input().split())
        results.append((c, d))

    print solve(results)
