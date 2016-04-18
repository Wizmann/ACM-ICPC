a = int(raw_input())
b = int(raw_input())

def check(x):
    l = len(str(x))
    xx = str(x * x)

    n = len(xx)
    
    ll = int('0' + xx[:n - l])
    rr = int('0' + xx[n - l:])
    
    return ll + rr == x   
    
ans = []
for i in xrange(a, b + 1):
    if check(i):
        ans.append(i)
        
if ans:
    print ' '.join(map(str, ans))
else:
    print 'INVALID RANGE'
