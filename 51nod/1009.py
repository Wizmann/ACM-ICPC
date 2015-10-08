def calc(l, m, r):
    m = int(m)
    ll, rr = int(l) if l else 0, int(r) if r else 0
    
    if m < 1:
        return ll * (10 ** len(r)) 
    elif m == 1:
        return ll * (10 ** len(r)) + rr + 1
    else:
        return (ll + 1) * (10 ** len(r))

n = raw_input()
l = len(n)

res = 0
for i in xrange(l):
    l, m, r = n[:i], n[i], n[i + 1:]
    res += calc(l, m, r)
print res
