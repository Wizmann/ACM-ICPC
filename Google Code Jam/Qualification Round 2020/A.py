# https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c

def solve(mat):
    n = len(mat)
    m = len(mat[0])
    assert (n == m)

    dia = []
    for i in xrange(n):
        dia.append(mat[i][i])

    row = 0
    for i in xrange(n):
        line = []
        for j in xrange(m):
            line.append(mat[i][j])
        if len(set(line)) != len(line):
            row += 1

    col = 0
    for j in xrange(m):
        line = []
        for i in xrange(n):
            line.append(mat[i][j])
        if len(set(line)) != len(line):
            col += 1

    return sum(dia), row, col


T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    mat = [
            map(int, raw_input().split())
            for i in xrange(n)
          ]
    (a, b, c) = solve(mat)
    print 'Case #%d: %d %d %d' % (case_ + 1, a, b, c)
