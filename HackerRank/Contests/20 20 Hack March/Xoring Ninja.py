MOD = 1000000007

def do_solve(ns):
    n = len(ns)
    ones = sum(ns)
    zeros = n - ones

    if ones == 0:
        return 0

    res = 0
    a, b = 1, 1
    
    y = pow(2, zeros, MOD)
    x = pow(2, ones - 1, MOD)
    return x * y % MOD

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
