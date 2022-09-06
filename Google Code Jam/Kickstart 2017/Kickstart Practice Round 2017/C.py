if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        print 'Case #%d:' % (case_ + 1),
        n, m = map(int, raw_input().split())

        u = min(n, m)
        print u * (1 + u) / 2
