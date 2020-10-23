#coding=utf-8

T = int(raw_input())
for case_ in xrange(T):
    (n, k) = map(int, raw_input().split())
    ns = sorted(map(int, raw_input().split()), reverse=True)
    for i in xrange(1, min(k + 1, n)):
        ns[0] += ns[i]
        ns[i] = 0
    ns.sort()
    print ns[-1] - ns[0]


'''
^^^TEST^^^
2
4 1
5 5 5 5
3 2
0 0 0
----
10
0
$$$TEST$$$
'''

