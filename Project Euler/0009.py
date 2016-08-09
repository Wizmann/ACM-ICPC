for i in xrange(1000):
    for j in xrange(1000 - i):
        k = 1000 - i - j
        if i and j and k and i * i + j * j == k * k:
            print i, j, k
            print i * j * k
