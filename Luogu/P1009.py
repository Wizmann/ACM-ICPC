n = int(raw_input())
res = 0
cur = 1
for i in xrange(1, n + 1):
    cur *= i
    res += cur
print res
