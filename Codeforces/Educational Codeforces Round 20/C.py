(n, k) = map(int, raw_input().split())

m = (1 + k) * k / 2
if n < m:
    print -1
else:
    s = set()
    for i in xrange(1, 10 ** 5):
        if n % i == 0:
            s.add(i)
            s.add(n / i)
            
    for i in sorted(list(s), reverse=True):
        if n / i >= m:
            for j in xrange(k - 1):
                u = i * (j + 1)
                n -= u
                print u,
            print n
            break

    else:
        print -1
