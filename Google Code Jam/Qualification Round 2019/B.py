T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = raw_input()
    res = ''
    for m in ns:
        res += {'E': 'S', 'S': 'E'}[m]
    print 'Case #%d: %s' % (case_ + 1, res)
