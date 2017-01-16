def do_solve(a):
    assert a + 1 >= 0
    ans = 0
    a += 1
    for i in xrange(32):
        cur = 1 << (i + 1)
        d, r = a / cur, a % cur
        ans += d * cur / 2
        ans += max(0, r - cur / 2)
    return ans

def do_solve_neg(a):
    if a >= 0:
        return 0
    return abs(a) * 32 - do_solve(abs(a) - 1)

def solve_range(a, b):
    assert a >= 0 and b >= 0
    return do_solve(b) - do_solve(a - 1)

def solve_range_neg(a, b):
    assert a <= 0 and b <= 0
    return do_solve_neg(a) - do_solve_neg(b + 1)

def solve(a, b):
    a, b = min(a, b), max(a, b)
    if b <= 0:
        return solve_range_neg(a, b)
    elif a <= 0 and b >= 0:
        return solve_range_neg(a, 0) + solve_range(0, b)
    else:
        return solve_range(a, b)

def test():
    ones = 0
    for i in xrange(1000):
        ones += '{:b}'.format(i).count('1')
        assert do_solve(i) == ones

    for i in xrange(100):
        ones = 0
        for j in xrange(i, 100):
            ones += '{:b}'.format(j).count('1')
        assert solve_range(i, j) == ones

    ones = 0
    for i in xrange(1, 1000):
        j = 0xFFFFFFFF - i + 1
        ones += '{:b}'.format(j).count('1')
        assert do_solve_neg(-i) == ones

    assert do_solve_neg(0) == 0
    assert solve(-2, 0) == 63
    assert solve(-3, 4) == 99
    assert solve(-1, 4) == 37
    assert solve(0, 0) == 0
    assert solve(1, 1) == 1
    assert solve(-1, -1) == 32
    print 'done'

if __name__ == '__main__':
    test()

    T = int(raw_input())
    for case_ in xrange(T):
        (a, b) = map(int, raw_input().split())
        print solve(a, b)
    
