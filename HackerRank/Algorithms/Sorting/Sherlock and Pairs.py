def solve():
    n = int(raw_input())
    d = {}
    ns = map(int, raw_input().split())
    for num in ns:
        d[num] = d.get(num, 0) + 1
    ans = 0
    for (key, value) in d.items():
        ans += value * (value - 1)
    print ans

T = int(raw_input())
for case_ in xrange(T):
    solve()
