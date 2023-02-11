INF = 10 ** 10
T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())

    xx, yy = INF, INF
    for x in xrange(min(100, n) + 1):
        if x == 1:
            if n % 2 == 0:
                y = n / 2
                xx, yy = 1, y
                break
        else:
            for y in xrange(min(100, n) + 1):
                m = (x ** y) * y + (y ** x) * x
                if m == n:
                    xx, yy = x, y
                    break
                if m > n:
                    break
        if xx != INF and yy != INF:
            break

    if yy != INF:
        assert (xx ** yy) * yy + (yy ** xx) * xx == n
        print xx, yy
    else:
        print -1
    

'''
^^^^^^TEST^^^^
7
3
7
42
31250
20732790
123456789
999999978
-------
<ignore>
$$$TEST$$$
'''

