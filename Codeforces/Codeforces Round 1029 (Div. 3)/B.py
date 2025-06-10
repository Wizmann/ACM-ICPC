def solve(n):
    flag = 1
    d = {}
    l, r = 0, 0
    for i in xrange(n, 0, -1):
        if flag:
            d[i] = r + 1
        else:
            d[i] = l - 1
        l, r = min(l, d[i]), max(r, d[i])
        flag ^= 1
    res = map(lambda (k, v): k, sorted(d.items(), key = lambda (k, v): v))
    return res

T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())

    res = solve(n)
    print ' '.join(map(str, res))

'''
^^^^TEST^^^^
4
3
6
4
5
-----------
<error>
$$$TEST$$$
'''

