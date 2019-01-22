(n, h) = map(int, raw_input().split())

ws = map(int, raw_input().split())
ls = map(int, raw_input().split())

res = 0

for i in xrange(n):
    u = (ws[i] - 0.25 * ls[i]) - h
    res = max(u, res)
    
print int(res + 0.99)
