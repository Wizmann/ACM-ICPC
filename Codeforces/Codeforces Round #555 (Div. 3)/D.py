def solve(n, k):
    u = k * (k - 1) / 2
    b = (n - u) / k
    #print n, u, b, n - b * k - u
    if b <= 0:
        return False, []
    res = [b for i in xrange(k)]
    n -= b * k
    for i in xrange(1, k):
        res[i] += i
        n -= i
    res[-1] += n
    if n and n == k - 1:
        res[-1] -= 1
        res[-2] += 1
    for i in xrange(k - 1):
        if res[i] * 2 < res[i + 1] or res[i] == res[i + 1]:
            return False, []
    return True, res

assert solve(26, 6)[0]
assert solve(9, 3)[0]
assert solve(8, 3)[0] == False
assert solve(1, 1)[0]
assert solve(9, 4)[0] == False

(n, k) = map(int, raw_input().split())
flag, ns = solve(n, k)

if flag:
    print 'YES'
    print ' '.join(map(str, ns))
else:
    print 'NO'
