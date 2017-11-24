T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    print sum(map(int, str(2 ** n)))
