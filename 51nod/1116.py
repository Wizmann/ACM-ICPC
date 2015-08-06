n = raw_input()

for i in xrange(36, 1, -1):
    u = int(n, i)
    if u % (i - 1) == 0:
        print i
        break
else:
    print 'No Solution'
