INF = 10 ** 10

def do_solve(n, c):
    # print n, c
    if c < n:
        return None
    elif n == 1:
        if c == 1:
            return [1]
        else:
            return None
    elif c == n:
        return range(1, n + 1)
    elif c >= 2 * n - 1:
        res = do_solve(n - 1, c - n)
        if not res:
            return None
        return map(lambda x: x + 1, res)[::-1] + [1]
    else:
        for i in xrange(2, n + 1):
            tot = ((i + 1) * i / 2) + (n - i)
            # print tot, c
            if tot >= c:
                rem = n - i
                res = do_solve(i, c - rem)
                if not res:
                    return None
                return res + range(i + 1, n + 1)
        return None


def calc(ns):
    n = len(ns)
    res = 0
    for i in xrange(n - 1):
        mini = INF
        minp = -1
        for j in xrange(i, n):
            if ns[j] < mini:
                mini = ns[j]
                minp = j
        ns = ns[:i] + ns[i : minp + 1][::-1] + ns[minp + 1:]
        res += minp + 1 - i
    return res

assert calc([4, 3, 2, 1]) == 6

def solve(n, c):
    return do_solve(n, c + 1)

def test(n, c):
    ns = solve(n, c)
    # ms = ns[:]
    # print ns[:], calc(ms)
    return calc(ns) == c

assert test(100, 1234)
assert test(100, 123)
assert test(5, 7)
assert test(4, 7)
assert test(4, 9)
assert test(4, 6)
assert test(3, 4)
assert solve(3, 5) == [2, 3, 1]
assert solve(3, 2) == [1, 2, 3]
assert solve(3, 3) == [2, 1, 3]
assert solve(2, 2) == [2, 1]
assert solve(2, 1) == [1, 2]

T = int(raw_input())

for case_ in xrange(T):
    n, c = map(int, raw_input().split())

    res = solve(n, c)
    if not res:
        print 'Case #%d: IMPOSSIBLE' % (case_ + 1)
    else:
        print 'Case #%d: %s' % (case_ + 1, ' '.join(map(str, res)))

'''
^^^TEST^^^
1
4 6
---
Case #1: 4 2 1 3
$$$TEST$$$

^^^TEST^^^
5
4 6
2 1
7 12
7 2
2 1000
----
Case #1: 4 2 1 3
Case #2: 1 2
Case #3: 7 6 5 4 3 2 1
Case #4: IMPOSSIBLE
Case #5: IMPOSSIBLE
$$$TEST$$$
'''

