ns = map(int, raw_input())

p = -1
for i in xrange(len(ns) - 2, -1, -1):
    if ns[i] % 2 != 0:
        continue
    if p == -1 or ns[i] < ns[-1]:
        p = i

if p == -1:
    print -1
else:
    ns[p], ns[-1] = ns[-1], ns[p]
    print ''.join(map(str, ns))
