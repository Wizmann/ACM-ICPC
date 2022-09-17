MOD = 998244353

n, m = map(int, raw_input().split())

def solve_odd(a, b, c, d):
    base = (c - 1) * m
    if a % 2 == 0:
        a += 1
    if b % 2 == 0:
        b -= 1
    if a > b:
        return 0
    assert (b - a) % 2 == 0
    cols = (b - a + 1 + 1) / 2
    tot = (base + a + base + b) * cols / 2
    assert c % 2 == 1 and d % 2 == 1
    rows = (d - c + 1 + 1) / 2
    res = (tot + tot + 2 * m * cols * (rows - 1)) * rows / 2
    return res

def solve_even(a, b, c, d):
    base = (c - 1) * m
    if a % 2 == 1:
        a += 1
    if b % 2 == 1:
        b -= 1
    if a > b:
        return 0
    assert (b - a) % 2 == 0
    cols = (b - a + 1 + 1) / 2
    tot = (base + a + base + b) * cols / 2
    assert c % 2 == 0 and d % 2 == 0
    rows = (d - c + 1 + 1) / 2
    # print tot, cols, rows
    res = (tot + tot + 2 * m * cols * (rows - 1)) * rows / 2
    return res

Q = int(raw_input())

for case_ in xrange(Q):
    (c, d, a, b) = map(int, raw_input().split())

    if c % 2 == 0:
        res1 = solve_even(a, b, c, d / 2 * 2)
        res2 = solve_odd(a, b, c + 1, (d - 1) / 2 * 2 + 1)
    else:
        res1 = solve_odd(a, b, c, ((d - 1) / 2) * 2 + 1)
        res2 = solve_even(a, b, c + 1, d / 2 * 2)

    # print res1, res2

    res = res1 + res2
    res %= MOD

    print res

'''
^^^^TEST^^^^
5 4
6
1 3 2 4
1 5 1 1
5 5 1 4
4 4 2 2
5 5 4 4
1 5 1 4
-------
28
27
36
14
0
104
$$$TEST$$$

^^^^TEST^^^^
1000000000 1000000000
3
1000000000 1000000000 1000000000 1000000000
165997482 306594988 719483261 992306147
1 1000000000 1 1000000000
-------
716070898
240994972
536839100
$$$TEST$$$$

^^^^TEST^^^^
999999999 999999999
3
999999999 999999999 999999999 999999999
216499784 840031647 84657913 415448790
1 999999999 1 999999999
--------
712559605
648737448
540261130
$$$$TEST$$$




'''

