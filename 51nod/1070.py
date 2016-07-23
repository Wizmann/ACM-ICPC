s = set([])

a, b = 1, 1
while a < 10 ** 10:
    a, b = b, a + b
    s.add(a)
    
n = int(raw_input())
for i in xrange(n):
    x = int(raw_input())
    if x in s:
        print 'B'
    else:
        print 'A'
