T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    s = raw_input()
    ns = map(int, s)

    if sum(ns) == n:
        m = n - n % 2
        a1, a2, b1, b2 = 1, m, 1, m / 2
    else:
        idx = -1
        for i in xrange(n):
            if ns[i] == 0:
                idx = i
                break

        if idx <= (n - 1) / 2:
            a1, a2, b1, b2 = (idx + 1), n, (idx + 2), n

        else:
            a1, a2, b1, b2 = 1, (idx + 1), 1, idx
    print a1, a2, b1, b2

    '''
    assert a2 - a1 + 1 >= n / 2
    assert b2 - b1 + 1 >= n / 2
    va = int(s[a1 - 1: a2], 2) 
    vb = int(s[b1 - 1: b2], 2)
    assert va == 0 or va % vb == 0
    '''

'''

^^^^TEST^^^
11
3
111
2
00
2
10
2
11
6
101111
9
111000111
8
10000000
5
11011
6
001111
3
101
30
100000000000000100000000000000
-------------
<SPJ>
$$$TEST$$$

'''
