if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        ns = sorted(map(int, raw_input().split()))
        ms = sorted(map(int, raw_input().split()), reverse=True)

        print 'Case #%d:' % (case_ + 1),
        print sum(map(lambda (x, y): x * y, zip(ns, ms)))
