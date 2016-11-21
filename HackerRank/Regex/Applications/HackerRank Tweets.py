n = int(raw_input())
print len(filter(lambda x: 'hackerrank' in x, [raw_input().lower() for i in xrange(n)]))
