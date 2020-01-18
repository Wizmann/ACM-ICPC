from collections import defaultdict
 
n, m = map(int, raw_input().split())
 
aced = set()
d = defaultdict(int)
pen = 0
for i in xrange(m):
    p, s = raw_input().split()
    p = int(p)
    s = s.strip()
 
    if p in aced:
        continue
