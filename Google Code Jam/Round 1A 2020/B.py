# https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1353

def solve(n):
    pattern = ''
    for i in xrange(100):
        m = n - i
        bits = '{:b}'.format(m)
        # print bits, bits.count('0'), i
        if bits.count('0') <= i:
            pattern = '0' * (i - bits.count('0')) + bits
            break
    # print pattern
    assert pattern
    row, col = 1, 1
    m = len(pattern)

    res = []
    for i in xrange(m - 1, -1, -1):
        if pattern[i] == '0':
            res.append((row, col))
            if col == row:
                col = row + 1
            row += 1
        else:
            if col == 1:
                for j in xrange(1, row + 1):
                    res.append((row, j))
                col = row + 1
            elif col == row:
                for j in xrange(row, 0, -1):
                    res.append((row, j))
                col = 1
            row += 1
    return res

def C(a, b):
    res = 1
    for i in xrange(a):
        res *= b - i
        res /= i + 1
    return res

def test(u):
    ps = solve(u)
    assert len(ps) <= 500
    v = 0
    for (a, b) in ps:
        v += C(b - 1, a - 1)
    return u == v


'''
for i in xrange(1, 100):
    assert test((10 ** 8) + i)
assert test(1234)
assert test(123456789)
'''

T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    print 'Case #%d:' % (case_ + 1)
    ps = solve(n)
    for (a, b) in ps:
        print a, b

