T = int(raw_input())

for case_ in xrange(T):
    a = set(list(raw_input()))
    b = set(list(raw_input()))
    
    if a & b:
        print 'YES'
    else:
        print 'NO'