factorials = [reduce(lambda x, y: x * y, range(1, i + 1), 1) for i in xrange(0, 101)]

#print factorials

ans = 0
for i in xrange(1, 101):
    for j in xrange(i + 1):
        v = factorials[i] / factorials[j] / factorials[i - j]
        print 'C', i, j, '=', v
        ans += 1 if (v > 1000000) else 0

print ans

