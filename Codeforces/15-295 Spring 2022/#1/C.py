def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(a, b):
    return a / gcd(a, b) * b

INF = 10 ** 30

'''
for i in xrange(2, 100):
    maxi = INF
    maxi_a, maxi_b = -1, -1
    for j in xrange(1, i / 2 + 1):
        a, b = j, i - j
        l = lcm(a, b)
        if l < maxi:
            maxi = l
            maxi_a = a
            maxi_b = b
    print i, maxi_a, maxi_b
'''

T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())

    mini = n - 1
    mini_a, mini_b = 1, n - 1
    i = 2
    while i * i <= n:
        a = n / i
        b = n - a
        l = lcm(a, b)
        if l < mini:
            mini = l
            mini_a = a
            mini_b = b
        i += 1
    print mini_a, mini_b


'''
^^^^TEST^^^
3
4
6
9
-------
2 2
3 3
3 6
$$$TEST$$$

^^^^TEST^^^
3
99
97
96
-------
33 66
1 96
48 48
$$$TEST$$$

'''

