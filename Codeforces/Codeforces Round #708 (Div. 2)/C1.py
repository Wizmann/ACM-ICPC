#coding=utf-8

def get_ans(n, m, k):
    res = [m, m]
    n -= 2 * m
    k -= 2
    twos = n - k
    ones = k - twos
    return res + [2] * twos + [1] * ones

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(ns):
    res = 1
    for num in ns:
        res = res * num / gcd(res, num)
    return res

def solve3(n, k):
    assert k == 3
    if n % 2 == 1:
        return [n / 2, n / 2, 1]

    if n % 2 == 0 and (n / 2) % 2 == 0:
        return [n / 2, n / 4, n / 4]
    else:
        return [(n - 2) / 2, (n - 2) / 2, 2]

def solve(n, k):
    ones = k - 3
    res = [1] * ones
    res += solve3(n - ones, 3)
    return res

def test_check(n, k, ns):
    # TODO: remove when submit
    assert len(ns) == k
    assert sum(ns) == n
    assert lcm(ns) <= n / 2

'''
for i in xrange(3, 10000):
    for j in xrange(3, 10):
        if j > i:
            break
        ns = solve(i, j)
        print '>>', i, ns
        test_check(i, j, ns)
print 'OK'
'''

T = int(raw_input())
for case_ in xrange(T):
    (n, k) = map(int, raw_input().split())
    ns = solve(n, k)
    print ' '.join(map(str, ns))



'''
^^^TEST^^^
3
3 3
8 3
14 3
----
1 1 1
4 2 2
2 6 6
$$$TEST$$$$

^^^TEST^^^
2
6 4
9 5
-----
1 2 2 1 
1 3 3 1 1 
$$$TEST$$$
'''


