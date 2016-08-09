ans = -1

base = [(9, 10), (90, 100), (900, 1000), (9000, 10000), (90000, 100000)]

DIGITS = set(map(str,range(1, 10)))

for lower, upper in base:
    for i in xrange(lower, upper):
        l = []
        for j in xrange(1, 10):
            v = i * j
            l += list(str(v))

            if len(l) >= 9:
                break
        if set(l) == DIGITS and len(l) == 9:
            vv = int(''.join(l))
            print vv
            ans = max(ans, vv)
print ans