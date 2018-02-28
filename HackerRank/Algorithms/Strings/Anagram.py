T = int(raw_input())

for case_ in xrange(T):
    s = raw_input()
    n = len(s)
    
    if n % 2 == 1:
        print -1
        continue
    
    a, b = s[:n / 2], s[n / 2:]
    da, db = {}, {}
    for c in a:
        da[c] = da.get(c, 0) + 1
    for c in b:
        db[c] = db.get(c, 0) + 1
    
    cnt = 0
    for i in xrange(26):
        c = chr(ord('a') + i)
        cnt += abs(da.get(c, 0) - db.get(c, 0))
    print cnt / 2