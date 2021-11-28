T = int(raw_input())

def solve(k, x):
    if (1 + k) * k / 2 >= x:
        l, r = 0, k
        while l <= r:
            m = (l + r) / 2
            tot = (1 + m) * m / 2
            if tot >= x:
                r = m - 1
            else:
                l = m + 1
        if (1 + l) * l / 2 < x:
            l += 1
        return l
    else:
        x -= (1 + k) * k / 2
        l, r = 1, k - 1
        while l <= r:
            m = (l + r) / 2
            tot = (k - 1 + k - m) * m / 2
            if tot >= x:
                r = m - 1
            else:
                l = m + 1
        if (k - 1 + k - l) * l / 2 < x:
            l += 1
        return l + k

for case_ in xrange(T):
    (k, x) = map(int, raw_input().split())

    res = solve(k, x)
    res = min(2 * k - 1, res)
    print res

'''
^^^^TEST^^^
7
4 6
4 7
1 2
3 7
2 5
100 1
1000000000 923456789987654321
------
3
4
1
4
3
1
1608737403
$$$TEST$$$$
'''



