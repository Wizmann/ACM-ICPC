if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        ns = map(int, raw_input().split())
        sg = reduce(lambda x, y: x ^ y, ns)
        if sg == 0 and max(ns) == 1:
            print 'First'
        elif sg != 0 and max(ns) > 1:
            print 'First'
        else:
            print 'Second'
