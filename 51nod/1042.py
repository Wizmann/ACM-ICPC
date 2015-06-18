def do_solve(n, digit):
    str_n = str(n)
    l = len(str_n)
    
    s = 0
    
    for i in xrange(l):
        a = int(str_n[0:i])   if str_n[0:i]   else 0
        b = int(str_n[i+1:l]) if str_n[i+1:l] else 0
        
        d = int(str_n[i:i+1])
            
        base = 10 ** (l - i - 1)
        
        if base > 1 and digit == 0 and l > 1:
            a -= 1
        
        if d < digit:
            s += a * base
        
        if d == digit:
            s += a * base + b + 1
        
        if d > digit:
            s+= (a + 1) * base
    return s

def solve(n):
    return [do_solve(n, i) for i in xrange(10)]

(a, b) = map(int, raw_input().split())
As, Bs = solve(a - 1), solve(b)

print '\n'.join(
    map(str,
        map(lambda (x, y): x - y,
            zip(Bs, As)
        )
    )
)
