def solve(n, a, b, c):
    a -= c
    b -= c
    if c == 0:
        return []
    if a + b <= 0 and c == 1 and n > 1:
        return []
    if a + b + c > n:
        return []
    res = [1 for i in xrange(n)]
    for i in xrange(a):
        res[a - i - 1] = n - i - 1
    for i in xrange(b):
        res[n - i - 1] = n - b + i
    if c == 1:
        if a == 0:
            res[a] = n
        else:
            res[n - b - 1] = n
    else:
        res[a] = n
        res[n - b - 1] = n
        for i in xrange(c - 2):
            res[a + i + 1] = n
    assert min(res) >= 1 and max(res) <= n
    return res

def check(ns):
    n = len(ns)
    view = [0 for i in xrange(n)]

    cur = 0
    for i in xrange(n):
        if ns[i] >= cur:
            view[i] += 1
            cur = ns[i]
    cur = 0
    for i in xrange(n - 1, -1, -1):
        if ns[i] >= cur:
            view[i] += 2
            cur = ns[i]

    a, b, c = 0, 0, 0
    for i in xrange(n):
        if view[i] & 1:
            a += 1
        if view[i] & 2:
            b += 1
        if view[i] == 3:
            c += 1
    return a, b, c


'''
def test(n):
    import random
    ns = [random.randint(1, n) for i in xrange(n)]
    (a, b, c) = check(ns)
    print a, b, c
    print ns
    ms = solve(n, a, b, c)
    assert check(ms) == (a, b, c)

for i in xrange(1000):
    test(8)
'''

# print solve(4, 1, 3, 1)
# print solve(4, 4, 4, 3)
# print solve(5, 3, 3, 2)
# print solve(5, 1, 1, 1)
# print solve(5, 5, 5, 5)
# print solve(5, 4, 4, 4)
# print solve(5, 3, 3, 3)
# print solve(5, 2, 2, 2)
# print solve(5, 2, 2, 1)
# print solve(5, 3, 3, 1)
# print solve(5, 4, 4, 1)
# print solve(5, 5, 1, 1)
# print solve(5, 4, 2, 1)
# print solve(5, 1, 2, 1)
# print solve(5, 2, 1, 1)
# print solve(5, 1, 2, 1)

T = int(raw_input())

for case_ in xrange(T):
    n, a, b, c = map(int, raw_input().split())
    print 'Case #%d:' % (case_ + 1),
    
    ns = solve(n, a, b, c)
    if not ns:
        print 'IMPOSSIBLE'
    else:
        print ' '.join(map(str, ns))

