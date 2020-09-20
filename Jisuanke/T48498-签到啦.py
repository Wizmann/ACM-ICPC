def solve(ns):
    n = len(ns)
    tot = 0
    for i in xrange(n - 1, 0, -1):
        tot += ns[i] - ns[i - 1]
    tot /= n - 1
    return ns[-1] + tot

n = int(raw_input())

ns = []
for i in xrange(n):
    a = int(raw_input())
    ns.append(a)

print solve(ns)

'''
^^TEST^^
4
1
2
3
4
---
5
$$TEST$$
'''
