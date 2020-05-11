# DEBUG = True

def log(*args):
    if globals().get("DEBUG", False) == False:
        return 
    for arg in args:
        print arg,
    print ''

def solve(ns):
    log(ns)
    if ns[0] == 0 or ns[-1] == 0:
        log("quit1")
        return []

    n = len(ns)
    if sum(ns) != n:
        log("quit2")
        return []

    ms = ns[:]
    d = [0 for i in xrange(n)]
    for i in xrange(n - 1, -1, -1):
        log(ms)
        while ms and ms[-1] == 0:
            ms.pop()

        assert ms
        d[i] = len(ms) - 1
        ms[-1] -= 1

        while ms and ms[-1] == 0:
            ms.pop()
    assert d[0] == 0
    assert d[-1] == n - 1

    row = 0
    for i in xrange(n):
        row = max(row, abs(i - d[i]))

    res = [ ['.' for i in xrange(n)] for j in xrange(row + 1)]

    for i in xrange(n):
        diff = abs(i - d[i])
        p = i
        for j in xrange(diff):
            if d[i] < p:
                res[j][p] = '/'
                p -= 1
            else:
                res[j][p] = '\\'
                p += 1
    return res

def do_test(res, end):
    if not res:
        return
    log(res)
    n = len(res[0])
    balls = [1 for i in xrange(n)]
    for line in res:
        nxt = [0 for i in xrange(n)]
        for j in xrange(n):
            if line[j] == '/':
                nxt[j - 1] += balls[j]
            elif line[j] == '\\':
                nxt[j + 1] += balls[j]
            elif line[j] == '.':
                nxt[j] += balls[j]
        balls = nxt
    assert balls == end

def pprint(res):
    for line in res:
        print ''.join(line)

def test(ns):
    res = solve(ns[:])
    do_test(res, ns[:])

test([2, 2, 0, 0, 1, 1])
test([2, 1, 0, 2, 0, 1])


T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())

    res = solve(ns[:])
    do_test(res, ns[:])

    if res:
        print 'Case #%d: %d' % (case_ + 1, len(res))
        pprint(res)
    else:
        print 'Case #%d: IMPOSSIBLE' % (case_ + 1)
