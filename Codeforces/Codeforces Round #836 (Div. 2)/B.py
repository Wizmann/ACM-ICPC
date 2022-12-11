T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())

    if n % 2 == 1:
        print ' '.join(map(str, [1] * n))
    else:
        print ' '.join(map(str, 
            [1, 3] + [2] * (n - 2)))
