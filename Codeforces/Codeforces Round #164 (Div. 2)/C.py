n, m = map(int, raw_input().split())
k = min(n, m) + 1
print k
for i in xrange(k):
    print n-i,i
