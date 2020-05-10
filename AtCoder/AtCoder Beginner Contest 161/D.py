# 20/05/10 cost:20min

def is_valid(num):
    if 1 <= num < 10:
        return True
    ns = map(int, str(num))
    n = len(ns)
    for i in xrange(n - 1):
        if abs(ns[i] - ns[i + 1]) > 1:
            return False
    return True

lunluns = []
for i in xrange(1, 10):
    if is_valid(i):
        lunluns.append(i)

d = {}

def dfs2(rem, pre, lt):
    if rem == 0:
        return 1
    key = (rem, pre, lt)
    if key in d:
        return d[key]

    res = 0
    if lt:
        for i in xrange(10):
            res += dfs2(rem - 1, i, lt and i == 0)
    else:
        for i in xrange(10):
            if abs(i - pre) <= 1:
                res += dfs2(rem - 1, i, False)
    d[key] = res
    return res

assert dfs2(1, -1, True) == 10
assert dfs2(1, 1, False) == 3

def dfs(cur, n, k, pre, lt, buf):
    if cur == n:
        return k == 1

    for i in xrange(10):
        if lt or abs(i - pre) <= 1:
            u = dfs2(n - cur - 1, i, lt and i == 0)
            if u < k:
                k -= u
            else:
                buf.append(i)
                assert dfs(cur + 1, n, k, i, lt and i == 0, buf)
                break
    return True

def solve(k):
    N = 500
    res = []
    assert dfs(0, N, k, -1, True, res)
    res = res[::-1]
    while res and res[-1] == 0:
        res.pop()
    if not res:
        res = [0]
    return ''.join(map(str, res[::-1]))

assert solve(3) == '2'
assert solve(1) == '0'
assert solve(2) == '1'
assert solve(4) == '3'

for i, num in enumerate(lunluns):
    assert solve(i + 2) == str(num)

if __name__ == '__main__':
    k = int(raw_input())
    k += 1
    print solve(k)
