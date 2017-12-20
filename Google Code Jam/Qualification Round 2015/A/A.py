def solve():
    (n, aud) = raw_input().split()
    n = int(n)
    aud = map(int, aud)
    stand = aud[0]
    res = 0
    for i in xrange(1, n + 1):
        u = aud[i]
        if not u:
            continue
        if i > stand:
            res += i - stand
            stand = i
        stand += u
    return res

T = int(raw_input())

for i in xrange(T):
    print 'Case #%d: %d' % (i + 1, solve())
