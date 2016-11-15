if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        ns = map(int, raw_input().split())
        
        print 'First' if reduce(lambda x, y: x ^ y, ns) else 'Second'
