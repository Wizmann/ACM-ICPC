def solve(n, ns):
    tot = sum(ns) / ((1 + n) * n / 2)

    if (ns[0] - tot) % (n - 1):
        return False

    b = (ns[0] - tot) / (n - 1)
    a = tot - b

    if a < 0 or b < 0:
        return False

    for i in xrange(n):
        A = a * (i + 1)
        B = b * (n - i)
        if A + B != ns[i]:
            return False
    return True

T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())
    if solve(n, ns):
        print 'YES'
    else:
        print 'NO'

'''
^^^^^^TEST^^^^
1
4
3 6 6 3
------
NO
$$$TEST$$$

^^^^^^TEST^^^^
6
4
3 6 6 3
5
21 18 15 12 9
10
2 6 10 2 5 5 1 2 4 10
7
10 2 16 12 8 20 4
2
52 101
2
10 2
----------
NO
YES
NO
NO
YES
NO
$$$$$$TEST$$$$
'''
