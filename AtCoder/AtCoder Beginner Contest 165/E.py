def solve(n, m):
    assert m * 2 + 1 <= n
    res = []

    maxi = (n - 1) / 2
    if maxi % 2 == 0:
        maxi -= 1
    p = 1
    for i in xrange(maxi, 0, -2):
        q = p + i
        res.append([p, q])
        p += 1

    p = maxi + 1 + 1
    maxi += 1
    for i in xrange(maxi, 1, -2):
        q = p + i
        if q > n:
            continue
        res.append([p, q])
        p += 1

    st1 = set()
    st2 = set()
    assert len(res) >= m
    for (a, b) in res:
        assert 1 <= a <= n
        assert 1 <= b <= n
        assert a != b
        assert not (set([a, b]) & st1)
        st1 |= set([a, b])
        diff = abs(a - b)
        assert not (set([diff, n - diff]) & st2)
        st2 |= set([diff, n - diff])
    return res[:m]

solve(9, 4)
solve(6, 2)
solve(7, 3)
solve(15, 6)
solve(12, 5)
solve(10000, 4999)

'''
for i in xrange(1, 100):
    for j in xrange(1, (i - 1) / 2 + 1):
        # print i, j
        solve(i, j)
'''

(n, m) = map(int, raw_input().split())

assert m * 2 + 1 <= n

for a, b in solve(n, m):
    print a, b
