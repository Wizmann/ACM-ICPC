def solve(st, end):
    if end - st + 1 <= 19:
        return reduce(lambda x, y: x * y, range(st, end + 1), 1)
    mid = (st + end) >> 1
    return solve(st, mid) * solve(mid + 1, end)

n = int(raw_input())
ans = str(solve(1, n))
 
l = len(ans)
for i in xrange(0, l, 1000):
    print ans[i: i + 1000]
