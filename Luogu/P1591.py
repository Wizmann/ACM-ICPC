T = int(raw_input())
for case_ in xrange(T):
    (n, a) = map(int, raw_input().split())
    s = str(reduce(lambda a, b: a * b, range(1, n + 1)))
    print s.count(str(a))
