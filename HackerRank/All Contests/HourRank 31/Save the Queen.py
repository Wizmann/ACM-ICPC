(n, m) = map(int, raw_input().split())
ns = map(int, raw_input().split())

def judge(u):
    rs = filter(lambda x: x >= u, ns)
    if len(rs) >= n:
        return True
    rem = n - len(rs)
    ls = filter(lambda x: x < u, ns)
    v = 1.0 * sum(ls) / rem
    return v >= u

l, r = 0.0, 1.0 * sum(ns)

while abs(r - l) > 1e-5:
    mid = (l + r) / 2
    if judge(mid):
        l = mid
    else:
        r = mid
print l
