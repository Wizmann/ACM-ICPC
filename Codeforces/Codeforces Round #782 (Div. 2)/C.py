INF = 10 ** 100

def solve(a, b, ns):
    n = len(ns)
    mini = INF

    cur = 0
    tot = sum(ns)
    for i in xrange(1, n):
        u = cur + b * (tot - ns[i - 1] * (n - i))
        # print i, u, cur
        mini = min(mini, u)

        cur += (a + b) * (ns[i] - ns[i - 1])
        tot -= ns[i]
    return mini

T = int(raw_input())

for case_ in xrange(T):
    (n, a, b) = map(int, raw_input().split())
    xs = map(int, raw_input().split())

    print solve(a, b, [0] + xs)

'''
^^^^^TEST^^^^
4
5 2 7
3 5 12 13 21
5 6 3
1 5 6 21 30
2 9 3
10 15
11 27182 31415
16 18 33 98 874 989 4848 20458 34365 38117 72030
---------
173
171
75
3298918744
$$$TEST$$$
'''

