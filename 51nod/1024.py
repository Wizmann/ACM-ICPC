(m, n, a, b) = map(int, raw_input().split())

print \
    len(
        set(
            [i ** j for i in xrange(a, a + n) for j in xrange(b, b + m)]
        )
    )
