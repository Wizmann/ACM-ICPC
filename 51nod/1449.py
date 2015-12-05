(w, m) = map(int, raw_input().split())
ws = [w ** i for i in xrange(32)]
n = len(ws)
wsum = [sum(ws[:i + 1]) for i in xrange(n)]

for i in xrange(n - 1, -1, -1):
    l = 0 if i == 0 else wsum[i - 1]
    r = wsum[i]
    if l < m <= r:
        m = abs(m - ws[i])
    
    if m == 0:
        break

print 'YES' if m == 0 else 'NO'
