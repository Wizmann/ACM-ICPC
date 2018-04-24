def solve(x, d):
    res = []
    cur = 1
    for i in xrange(64):
        if x & (1 << i):
            res += [cur] * i
            cur += d
            res.append(cur)
            cur += d
    res.sort()
    return res

def count(l, d):
    n = len(l)
    cnt = 0
    for i in xrange(1 << n):
        cur = []
        for j in xrange(n):
            if i & (1 << j):
                cur.append(l[j])
        if not cur:
            continue
        if max(cur) - min(cur) < d:
            cnt += 1
    return cnt

def test(x, d):
    return count(solve(x, d), d) == x

assert test(10, 5)
assert test(5, 3)
assert test(10, 2)
assert test(10, 3)
assert test(10, 4)
assert test(10, 1)
for i in xrange(1, 10):
    for j in xrange(1, 10):
        assert test(i, j)

(n, m) = map(int, raw_input().split())
res = solve(n, m)
print len(res)
print ' '.join(map(str, res))
