n = int(raw_input())

print str(sum(map(int, [raw_input() for i in xrange(n)])))[:10]
