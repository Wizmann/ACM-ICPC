MAXI = (10 ** 10) + 123456

a, b = 1, 1
s = set()

while a < MAXI:
    s.add(a)
    a, b = b, a + b

T = int(raw_input())
for case_ in xrange(T):
    x = int(raw_input())
    print 'IsFibo' if x in s else 'IsNotFibo'
