#coding=utf-8

'''
xi = (A * i + B) // M
求sum(x_0...x_n-1)
'''

def floor_sum(n, m, a, b):
    ans = 0
    if a >= m:
        ans += (n - 1) * n * (a / m) / 2
        a %= m
    if b >= m:
        ans += n * (b / m)
        b %= m

    y_max = (a * n + b) / m
    x_max = (y_max * m - b)
    if y_max == 0:
        return ans
    ans += (n - (x_max + a - 1) / a) * y_max
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a)
    return ans

T = int(raw_input())
for case_ in xrange(T):
    n, m, a, b = map(int, raw_input().split())
    print floor_sum(n, m, a, b)

'''
^^^TEST^^^
5
4 10 6 3
6 5 4 3
1 1 0 0
31415 92653 58979 32384
1000000000 1000000000 999999999 999999999
-----
3
13
0
314095480
499999999500000000
$$$TEST$$$
'''
