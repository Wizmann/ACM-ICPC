ans = 0
for i in xrange(1, 10):
    for j in xrange(1, 1000):
        if len(str(i ** j)) == j:
            ans += 1
print ans

