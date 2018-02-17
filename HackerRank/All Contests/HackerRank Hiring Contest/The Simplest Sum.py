MOD = (10 ** 9) + 7

def do_solve(k, n):
    res = 0

    i = 1
    while i <= n:
        res = (res + i) % MOD
        i = (i * k) + 1

    return res

assert do_solve(2, 0) == 0
assert do_solve(2, 1) == 1
assert do_solve(2, 2) == 1
assert do_solve(2, 3) == 4
assert do_solve(2, 4) == 4
assert do_solve(2, 5) == 4

def do_solve2(k, x):
    res = 0

    i = 1
    s = 0
    while i <= x:
        s += i

        j = (i * k) + 1
        delta = min(x, j - 1) - i + 1
        res = (res + delta * s) % MOD
        i = j

    return res

assert do_solve2(2, 5) == 14

def solve(k, a, b):
    res = do_solve2(k, b) - do_solve2(k, a - 1)
    return ((res % MOD) + MOD) % MOD

assert solve(2, 1, 5) == 14

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        (k, a, b) = map(int, raw_input().split())
        print solve(k, a, b)
