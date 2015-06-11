res = 0
l = []
for i in xrange(1000001):
    if '7' in str(i) or i % 7 == 0:
        pass
    else:
        res += i ** 2
    l.append(res)
    
T = int(raw_input())

for i in xrange(T):
    n = int(raw_input())
    print l[n]
