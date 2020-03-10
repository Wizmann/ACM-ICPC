# https://codeforces.com/contest/1312/problem/B

def solve(ns):
    ns.sort(reverse=True)
    '''
    n = len(ns)
    for i in xrange(n):
        for j in xrange(i + 1, n):
            assert j - ns[j] != i - ns[i]
    '''
    return ns
 
from random import randint
 
'''
for i in xrange(100):
    ns = [randint(1, 100) for i in xrange(100)]
    solve(ns)
print 'ok'
'''
 
T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())
    ns = solve(ns)
    for num in ns:
        print num,
    print ''
