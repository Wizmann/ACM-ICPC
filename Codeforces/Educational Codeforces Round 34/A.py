def solve(n):
    for i in xrange(n / 7 + 1):
        r = n - i * 7
        if r % 3 == 0:
            return True
    return False

assert solve(6)
assert solve(7)
assert not solve(5)

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        print 'YES' if solve(n) else 'NO'
