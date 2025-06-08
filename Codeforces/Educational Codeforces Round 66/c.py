INF = 10 ** 100

def check(ns, v, k):
    u = []
    for num in ns:
        u.append(abs(num - v))
    u.sort()
    return u[k]

def solve(n, k, ns):
    mini = INF
    minv = -1
    for i in xrange(n):
        if i + k < n:
            value = abs(ns[i] - ns[i + k] + 1) / 2
            if value < mini:
                minv = (ns[i] + ns[i + k]) / 2
                mini = value
    #print "1>>", minv, mini
    return minv

def brute_force(n, k, ns):
    LL, RR = min(ns) - 100, max(ns) + 100

    mini = INF
    minv = -1
    for i in xrange(LL, RR + 1):
        res = check(ns, i, k)
        if res < mini:
            minv = i
            mini = res
    print "2>>", minv, mini
    return minv

#assert solve(3, 2, [1, 2, 5]) == 3
#assert solve(1, 0, [4]) == 4
#assert solve(5, 3, [3, 4, 10, 20, 23]) == brute_force(5, 3, [3, 4, 10, 20, 23])

'''
from random import randint
n = 19
ns = sorted([randint(1, 50) for i in xrange(n)])
k = randint(0, n - 1)
print n, k, ns
print solve(n, k, ns)
print brute_force(n, k, ns)
assert solve(n, k, ns) == brute_force(n, k, ns)

n = 20
ns = sorted([randint(1, 50) for i in xrange(n)])
k = randint(0, n - 1)
print n, k, ns
print solve(n, k, ns)
print brute_force(n, k, ns)
assert solve(n, k, ns) == brute_force(n, k, ns)
'''

T = int(raw_input())
for case_ in xrange(T):
    (n, k) = map(int, raw_input().split())
    ns = map(int, raw_input().split())
    print solve(n, k, ns)
