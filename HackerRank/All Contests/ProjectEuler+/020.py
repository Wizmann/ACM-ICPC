if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        print sum(map(int, str(reduce(lambda x, y: x * y, range(1, n + 1), 1))))
