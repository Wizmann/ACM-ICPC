if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        print 'Case #%d:' % (case_ + 1),
        n = int(raw_input())
        ns = sorted([raw_input() for i in xrange(n)], key = lambda name: (-len(set(name.replace(' ', ''))), name))
        print ns[0]
