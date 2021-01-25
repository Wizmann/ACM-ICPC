from collections import defaultdict

T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    A = map(int, list(raw_input()))
    B = [0 for i in xrange(n)]
    pre = 0
    for i in xrange(n):
        maxi = -1
        maxv = -1
        for j in [0, 1]:
            if A[i] + j != pre and A[i] + j > maxv:
                maxv = A[i] + j
                maxi = j
        B[i] = maxi
        pre = maxv
    print ''.join(map(str, B))


'''
^^^TEST^^^
5
1
0
3
011
3
110
6
111000
6
001011
----
1
110
100
101101
101110
$$$TEST$$$
'''


