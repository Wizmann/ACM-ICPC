T = int(raw_input())

for case_ in xrange(T):
    (n, m) = map(int, raw_input().split())
    s = 0
    for i in xrange(n):
        s += sum(map(int, raw_input().split()))
    if s & 1:
        print 'yadang'
    else:
        print 'xiawa'
