from math import sqrt

def get_all(v):
    s = set()
    for i in xrange(1, int(sqrt(v) + 1)):
        if v % i == 0:
            s.add(i)
            s.add(v / i)
    return sum(list(s)) - v


ans = 0

for i in xrange(1, 10000):
    a = get_all(i)
    b = get_all(a)
    
    if b == i and i != a:
        print i, a
        ans += i + a
print ans/2
