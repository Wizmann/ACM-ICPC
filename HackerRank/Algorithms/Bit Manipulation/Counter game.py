def lowbit(x):
    return x & (-x)

def solve(n):
    if n == 1:
        return False
    if (n & (n - 1)) == 0:
        return not solve(n >> 1)
    else:
        m = n
        while m != lowbit(m):
            m -= lowbit(m)
        return not solve(n - m)
    
assert solve(1) == False
assert solve(6) == False

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        print 'Louise' if solve(n) else 'Richard '
