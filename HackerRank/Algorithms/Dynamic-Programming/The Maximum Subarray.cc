def max_subarray(ns):
    ans = -0x3f3f3f3f
    s = 0
    for num in ns:
        if s < 0:
            s = 0
        s += num
        ans = max(ans, s)
    return ans

T = int(raw_input())

for i in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())

    ans1 = max_subarray(ns)
    if not filter(lambda x: x > 0, ns):
        ans2 = max(ns)
    else:
        ans2 = sum(filter(lambda x: x > 0, ns))
    print ans1, ans2
