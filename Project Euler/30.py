ans = 0
for i in xrange(2, 1000000):
    s = sum(map(lambda x: x ** 5, map(int, str(i))))
    if s == i:
        print i
        ans += i
        
print ans
