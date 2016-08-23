def solve(n):
    res = [[-1 for i in xrange(n)] for j in xrange(n)]
    ns_odd = range(1, n * n + 1, 2)
    ns_even = range(2, n * n + 1, 2)

    idx_odd, idx_even = 0, 0

    l = 1
    for i in xrange(n):
        for j in xrange(l):
            res[i][n / 2 - l / 2 + j] = ns_odd[idx_odd]
            idx_odd += 1
        if i < n / 2:
            l += 2
        else:
            l -= 2

    for i in xrange(n):
        for j in xrange(n):
            if res[i][j] == -1:
                res[i][j] = ns_even[idx_even]
                idx_even += 1
    return res

def test(n, matrix):
    for i in xrange(n):
        sa, sb = 0, 0
        for j in xrange(n):
            sa += matrix[i][j]
            sb += matrix[j][i]
        assert sa % 2 == 1 and sb % 2 == 1

    sa, sb = 0, 0
    for i in xrange(n):
        sa += matrix[i][i]
        sb += matrix[i][n - i - 1]
    assert sa % 2 == 1 and sb % 2 == 1

    ns = []
    for i in xrange(n):
        for j in xrange(n):
            ns.append(matrix[i][j])
    assert set(ns) == set(range(1, n * n + 1))
    assert -1 not in ns

for i in xrange(1, 50, 2):
    m = solve(i)
    test(i, m)

if __name__ == '__main__':
    n = int(raw_input())
    m = solve(n)
    for i in xrange(n):
        for j in xrange(n):
            print m[i][j],
        print ''
