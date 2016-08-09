def is_palin(x):
    v = str(x)
    return v == v[::-1]


ans = 0

for i in xrange(100, 1000):
    for j in xrange(100, 1000):
        t = i * j
        if is_palin(t):
            ans = max(ans, t)
            
print ans
