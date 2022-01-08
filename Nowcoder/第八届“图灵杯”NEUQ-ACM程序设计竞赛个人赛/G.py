#coding=utf-8

def solve(n, k, ns):
    maxi = max(ns)
    head = 0
    headc = 0
    for num in ns:
        if num == maxi:
            break
        head += num
        headc += 1

    rem = sum(ns) - maxi
    remc = len(ns) - 1

    tot = k

    tot -= headc
    if tot <= 0:
        return False

    u = tot % (maxi + remc)
    v = tot / (maxi + remc)

    if v == 0:
        if tot <= maxi:
            return True
        return False

    if u <= maxi:
        return True

    assert u > maxi

    u -= (head - headc)
    if u <= maxi:
        return True

    assert u > maxi

    u -= (rem - remc) * v
    if u <= maxi:
        return True


    return False

T = int(raw_input())

for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    ns = map(int, raw_input().split())

    print 'YES' if solve(n, k, ns) else 'NO'

'''
^^^TEST^^^
1
4 3
1 2 3 2
-----
YES
$$$TEST$$$

^^^TEST^^^
1
5 8
1 2 3 2 1
-----
NO
$$$TEST$$$
'''

