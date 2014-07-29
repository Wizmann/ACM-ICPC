even, odd = 0, 0

def solve(xs):
    if not xs:
        return
    global even
    global odd
    _even, _odd = 0, 0
    
    now = xs[0]
    for x in xs:
        if (x - now + 1) % 2:
            _odd += 1
        else:
            _even += 1
    even += _even
    odd += _odd
    #print '>>', _even, _odd
    pre = xs[0]
    for x in xs[1:]:
        predis = x - pre
        pre = x
        #print '>>', predis
        if predis % 2:
            if _odd:
                _odd -= 1
            _even, _odd = _odd, _even
        else:
            if _odd:
                _odd -= 1
        
        even += _even
        odd += _odd
        

cs = raw_input()
a, b = [], []

for i, c in enumerate(cs):
    if c == 'a':
        a.append(i)
    else:
        b.append(i)
        
solve(a)
#print even, odd
solve(b)

print even, odd
