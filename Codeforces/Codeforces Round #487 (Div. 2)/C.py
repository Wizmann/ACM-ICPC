def solve(a, b, c, d):
    fs = sorted([ [a, 'A'], [b, 'B'], [c, 'C'], [d, 'D'] ])

    while fs[0][0] == '0':
        fs.pop(0)

    assert len(fs) >= 2

    fs[0][0] -= 1
    fs[1][0] -= 1

    c = fs[0][1]
    res = [ list(c * 49) for i in xrange(30) ]

    p, q = 1, 1
    for (cnt, c) in fs[1:]:
        for i in xrange(cnt):
            res[p][q] = c
            q += 2
            if q >= 48:
                p, q = p + 2, 1
    c = fs[1][1]
    res += [ list(c * 49) for i in xrange(20) ]

    p, q = 31, 1

    cnt, c = fs[0]
    for i in xrange(cnt):
        res[p][q] = c
        q += 2
        if q >= 48:
            p, q = p + 2, 1
    n = len(res)
    ans = ''
    for line in res:
        ans += ''.join(line) + '\n'
        m = len(line)
    print n, m
    print ans

if __name__ == '__main__':
    (a, b, c, d) = map(int, raw_input().split())
    solve(a, b, c, d)
