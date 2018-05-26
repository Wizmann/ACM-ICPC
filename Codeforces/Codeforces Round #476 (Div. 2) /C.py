def solve(n, k, m, d):
    res = 0
    if (n / m / k) + (1 if (n / m) % k else 0) <= d:
        res = m
    for i in xrange(d):
        u = n / (k * i + 1)
        v = n / (k * i + k)
        if u > m and v > m:
            continue
        elif u <= m and v <= m:
            res = max(res, max(u, v) * (i + 1))
        else:
            l, r = 1, k
            while l <= r:
                mid = (l + r) >> 1
                if n / (k * i + mid) > m:
                    l = mid + 1
                else:
                    r = mid - 1
            res = max(res, (n / (k * i + l)) * (i + 1))
    return res

assert solve(216, 137, 202, 208) == 202
assert solve(885, 2, 160, 842) == 504
assert solve(20, 4, 5, 2) == 8
assert solve(30, 9, 4, 1) == 4

if __name__ == '__main__':
    (n, k, m, d) = map(int, raw_input().split())
    print solve(n, k, m, d)

