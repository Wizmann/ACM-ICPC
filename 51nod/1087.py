def solve():
    x = int(raw_input())
    fun = lambda x: (1 + x) * x / 2
    
    l, r = 1, 10 ** 9
    while l <= r:
        m = (l + r) >> 1
        u = fun(m)
        if u > x:
            r = m - 1
        else:
            l = m + 1
    x -= fun(r)
    if x == 1:
        return 1
    else:
        return 0

T = int(raw_input())

for i in xrange(T):
    print solve()
