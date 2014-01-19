def solve(v):
    s = 10
    d = {}
    p = 1
    
    while True:
        if s in d:
            return p - d[s]
        d[s] = p
        if s >= v:
            s %= v
        s *= 10
        p += 1
        if not s:
            return 0
        
            

maxlen = 0
ans = -1

for i in xrange(2, 1000):
    d = solve(i)
    print ">>" , d, i
    if d > maxlen:
        maxlen = d
        ans = i

print ans
