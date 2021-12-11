def A(n, m):
    if n == 1 and m == 0:
        return 2
    elif n == 0:
        assert m >= 0
        return 1
    elif m == 0:
        assert n >= 2
        return (n + 2)
    else:
        assert(n >= 1 and m >= 1)
        return A(A(n - 1, m), m - 1)

MOD = 998244353

def solve(n, m):
    if m == 0:
        return (n + 2) % MOD
    elif m == 1:
        if n == 0:
            return 1
        return n * 2 % MOD
    else:
        return pow(2, n, MOD)

assert A(3, 0) % MOD == solve(3, 0)
assert A(3, 1) % MOD == solve(3, 1)
assert A(3, 2) % MOD == solve(3, 2)

T = int(raw_input())

import sys
for case_ in xrange(T):
    (n, m) = map(int, raw_input().split())
    sys.stdout.write("%d" % solve(n, m))
    if case_ != T - 1:
        print ''

'''
^^^TEST^^^
3
3 0
3 1
3 2
-----
5
6
8
$$$TEST$$$
'''

    
