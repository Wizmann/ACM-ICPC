
def solve(ns, k):
    n = len(ns)
    ms = [0 for i in xrange(n)]
    step = k
    for i in xrange(n):
        if step == 0:
            break
        if ns[i] == 0:
            if k % 2 == 0:
                ms[i] = 1
                step -= 1
        else:
            if k % 2 == 1:
                ms[i] = 1
                step -= 1
    ms[n - 1] += step

    k %= 2
    for i in xrange(n):
        ns[i] ^= (ms[i] % 2) ^ k
    return ns, ms


T = int(raw_input())

for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    ns = map(int, raw_input())

    s, ms = solve(ns, k)

    print ''.join(map(str, s))
    print ' '.join(map(str, ms))

'''
^^^^^TEST^^^
6
6 3
100001
6 4
100011
6 0
000000
6 1
111001
6 11
101100
6 12
001110
-------
111110
1 0 0 2 0 0 
111110
0 1 1 1 0 1 
000000
0 0 0 0 0 0 
100110
1 0 0 0 0 0 
111111
1 2 1 3 0 4 
111110
1 1 4 2 0 4
$$$TEST$$$
'''


