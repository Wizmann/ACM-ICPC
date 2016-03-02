MOD = 1000000007

def do_solve(ns):
    n = len(ns)
    ones = sum(ns)
    zeros = n - ones

    assert ones + zeros == n

    res = 0
    a, b = 1, 1
    y = pow(2, zeros, MOD)
    for i in xrange(1, ones + 1):
        a = a * (ones - i + 1) % MOD
        b = b * pow(i, MOD - 2, MOD) % MOD
        if i % 2 != 0:
            c = (a * b * y) % MOD
            res = (res + c) % MOD
    return res

def solve():
    n = int(raw_input())
    nums = map(int, raw_input().split())

    ans = 0
    for i in xrange(40):
        ns = map(lambda x: 1 if (x & (1 << i)) else 0, nums)
        ans = (ans + pow(2, i, MOD) * do_solve(ns)) % MOD

    print ans % MOD

T = int(raw_input())

for case_ in xrange(T):
    solve()
