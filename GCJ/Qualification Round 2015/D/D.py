def solve():
    (x, r, c) = map(int, raw_input().split())
    
    if x >= 7:
        return False
    
    #print x, r, c 
    if x > max(r, c) or (x + 1) // 2 > min(r, c):
        return False
    if (r * c) % x:
        return False
    n = (r * c) / x
    black = 0
    white = 0
    for i in xrange(r):
        if i % 2 == 0:
            _black = (c + 1) / 2
            _white = c - _black
        else:
            _white = (c + 1) / 2
            _black = c - _white
        
        black += _black
        white += _white

    if black != white and x % 2 == 0:
        return False
        
    if black != white and x % 2 == 1 and n % 2 == 0:
        return False
    
    if black == white and x % 2 == 1 and n % 2 != 0:
        return False
        
    return True
        


T = int(raw_input())

for i in xrange(T):
    print 'Case #%d:' % (i + 1), 'GABRIEL' if solve() else 'RICHARD'
