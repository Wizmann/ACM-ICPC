N = 123456

ns = [0, 1]

for i in xrange(2, N):
    if i % 2 == 0:
        ns.append(ns[i / 2])
    else:
        ns.append(ns[i / 2] + ns[i / 2 + 1])
        
for i in xrange(1, N):
    ns[i] = max(ns[i], ns[i - 1])
    
T = int(raw_input())
for i in xrange(T):
    n = int(raw_input())
    print ns[n]
