n = int(raw_input())
ns = map(int, raw_input().split())

for i in xrange(n):
    ns[i] -= n - i
    
print 'Happy' if len(set(ns)) == n else 'Sad'
