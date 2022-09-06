#python3

INF = 10 ** 100

T = int(input())

for case_ in range(T):
    n = int(input())
    ns = [0] + list(map(int, input().split()))
    m = int(input())
    ms = [0] + list(map(int, input().split()))

    tot_n = sum(ns)
    tot_m = sum(ms)

    for i in range(1, n + 1):
        ns[i] += ns[i - 1]

    for i in range(1, m + 1):
        ms[i] += ms[i - 1]

    k = int(input())

    maxi = 0

    p = 0
    while p <= k:
        q = k - p

        rem_n = n - p
        rem_m = m - q
        if q < 0 or rem_n < 0 or rem_m < 0:
            p += 1
            continue

        v1 = INF
        for i in range(rem_n, n + 1):
            v1 = min(v1, ns[i] - ns[i - rem_n])

        v2 = INF
        for i in range(rem_m, m + 1):
            v2 = min(v2, ms[i] - ms[i - rem_m])

        maxi = max(maxi, tot_n + tot_m - (v1 + v2))
        p += 1

    print('Case #%d: %d' % (case_ + 1, maxi))


'''
^^^^^TEST^^^^
2
3
3 1 2
4
2 8 1 9
5
4
1 100 4 3
6
15 10 12 5 1 10
6
----------
Case #1: 24
Case #2: 148
$$$TEST$$$$
'''



