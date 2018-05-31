INF = 10 ** 10

(n, m) = map(int, raw_input().split())

ms = map(int, [raw_input() for i in xrange(m)])[::-1]
ns = sorted(set(range(1, n + 1)) - set(ms))[::-1]

while ms or ns:
    a = INF if not ms else ms[-1]
    b = INF if not ns else ns[-1]

    if a < b:
        print a
        ms.pop()
    else:
        print b
        ns.pop()


