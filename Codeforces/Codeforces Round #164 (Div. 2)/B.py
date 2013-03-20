n = int(raw_input())
print sum([(i+1)*(n-i)-i for i in xrange(n)])
