import sys
if sys.subversion[0] == "PyPy":
    import io, atexit
    sys.stdout = io.BytesIO()
    atexit.register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))
    
    sys.stdin = io.BytesIO(sys.stdin.read())
    input = lambda: sys.stdin.readline().rstrip()

def solve(n, a, b, injections = {}):
    g = 0
    tot = 0
    while tot < a and g < n:
        g += 1
        nxt = tot + 2 * (n - g)
        if nxt >= a:
            break
        else:
            tot = nxt
    else:
        if g == n:
            return [1]

    injections.get(0, lambda x: 0)(locals())

    rem = a - tot
    u = (rem + 1) / 2

    injections.get(1, lambda x: 0)(locals())

    res = []
    ptr = a
    v = 0
    if rem % 2 == 0:
        res.append(g + u)
        u += 1
        ptr += 1

    injections.get(2, lambda x: 0)(locals())

    while ptr <= b:
        if g + u > n:
            g += 1
            u = 1
            assert v == 0
            if g == n:
                g = 1
        if v % 2 == 0:
            res.append(g)
        else:
            res.append(g + u)
            u += 1
        v ^= 1
        ptr += 1
        # print res
    return res

def test():
    def inj2(context):
        assert context['res'] == []
        assert context['v'] == 0
        assert context['u'] == 1
    assert solve(2, 1, 3, {2: inj2}) == [1, 2, 1]
    def inj2(context):
        assert context['rem'] == 2
        assert context['g'] == 2
        assert context['u'] == 2
        assert context['res'] == [3]
    assert solve(3, 6, 7, {2: inj2}) == [3, 1]

    assert solve(99995, 9998900031, 9998900031) == [1]

    def inj0(context):
        assert (context['g'] == 1)
        assert (context['tot'] == 0)

    def inj1(context):
        assert (context['rem'] == 3)
        assert (context['u'] == 2)

    assert solve(3, 3, 7, {0: inj0, 1: inj0}) == [1, 3, 2, 3, 1]
    assert solve(3, 1, 2) == [1, 2]
    assert solve(3, 1, 3) == [1, 2, 1]
    
test()

T = int(raw_input())
for case_ in xrange(T):
    n, a, b = map(int, raw_input().split())
    res = solve(n, a, b)
    print ' '.join(map(str, res))
