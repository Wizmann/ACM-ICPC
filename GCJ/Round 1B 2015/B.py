def solve(n, m, c):
    res = 0
    
    a1 = (n * m + 1) / 2
    if c <= a1:
        return 0
    c -= a1

    a2 = (2 if n % 2 == 0 or m % 2 == 0 else 0)
    if c <= a2:
        return 2 * c
    
    c -= a2
    res += 2 * a2

    a3 = 0
    a3 += (m - 1) / 2
    
    if n % 2:
        a3 += (m - 1) / 2
    else:
        a3 += (m - 2) / 2
        
    a3 += (n - 1) / 2
    
    if m % 2:
        a3 += (n - 1) / 2
    else:
        a3 += (n - 2) / 2
    
    if c <= a3:
        return res + c * 3
    
    c -= a3
    res += 3 * a3
    
    return res + 4 * c
    
def solve1(n, m, c):
    res = 0
    
    a1 = (n * m - 1) / 2
    if c <= a1:
        return 0
    c -= a1

    a2 = 4
    if c <= a2:
        return 2 * c
    
    c -= a2
    res += 2 * a2

    a3 = ((n - 2) / 2 + (m - 2) / 2) * 2
    if c <= a3:
        return res + c * 3
    
    c -= a3
    res += 3 * a3
    
    return res + 4 * c
    
def solvexxx(x, c):
    if x % 2:
        c -= (x + 1) / 2
        if c <= 0:
            return 0
        return c * 2
    else:
        c -= (x + 1) / 2
        if c <= 0:
            return 0
        if c == 1:
            return 1
        return 1 + (c - 1) * 2

T = int(raw_input())

for i in xrange(T):
    (n, m, c) = map(int, raw_input().split())
    
    ans = 0
    if n == 1 or m == 1:
        if n == m:
            ans = 0
        else:
            ans = solvexxx(max(n, m), c)
    elif n == m == 2:
        if c <= 2:
            ans = 0.
        elif c == 3:
            ans = 2
        else:
            ans = 4
    else:
        ans = solve(n, m, c)
        if n % 2 and m % 2:
            ans = min(ans, solve1(n, m, c))
    print 'Case #%d: %d' % (i + 1, ans)
