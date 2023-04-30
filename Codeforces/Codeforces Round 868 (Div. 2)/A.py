#coding=utf-8

def solve(n, k):
    for i in xrange(n):
        l, r = i, n - i

        tot = (l * (l - 1) / 2) + (r * (r - 1) / 2)
        if tot == k:
            return [-1] * l + [1] * r
    return []

T = int(raw_input())

for case_ in xrange(T):
    n, k = map(int, raw_input().split())

    res = solve(n, k)
    if not res:
        print 'NO'
    else:
        print 'YES'
        print ' '.join(map(str, res))

'''
^^^^^TEST^^^^
7
2 0
2 1
3 1
3 2
3 3
5 4
5 5
---------------
YES
1 -1 
YES
1 1 
YES
1 -1 1 
NO
YES
1 1 1 
YES
-1 1 -1 1 1 
NO
$$$$$$$TEST$$$

'''
