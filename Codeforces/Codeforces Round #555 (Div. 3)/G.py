(n, m) = map(int, raw_input().split())
mat = [map(int, raw_input().split()) for i in xrange(n)]

my = [0 for i in xrange(n)]
mx = [0 for i in xrange(m)]

def cell(y, x):
    return mat[y][x] ^ my[y] ^ mx[x]

def check(y, x):
    assert y == 0
    assert cell(y, x) == 0

    # first line
    for i in xrange(x + 1, m):
        if cell(0, i) == 0:
            mx[i] ^= 1

    prefix = (x == m - 1)
    if prefix:
        assert sum([cell(0, j) for j in xrange(m)]) == 0

    for i in xrange(1, n):
        line = [cell(i, j) for j in xrange(m)]
        s = sum(line)
        if s == 0:
            if not prefix:
                my[i] ^= 1
            else:
                pass
        elif s == m:
            if prefix:
                my[i] ^= 1
        elif prefix == True:
            if line[0] == 1:
                my[i] ^= 1
                line = [cell(i, j) for j in xrange(m)]

            if line != sorted(line):
                return False
            prefix = False
        else:
            return False
    return True

def solve():
    for i in xrange(m):
        if cell(0, i) == 1:
            mx[i] ^= 1
        if check(0, i):
            return True

    return False

if solve():
    print 'YES'
    print ''.join(map(str, my))
    print ''.join(map(str, mx))
else:
    print 'NO'
