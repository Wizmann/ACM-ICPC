ans = 0
for i in xrange(100):
    for j in xrange(100):
        k = sum(map(int, str(pow(i, j))))
        ans = max(ans, k)
print ans
