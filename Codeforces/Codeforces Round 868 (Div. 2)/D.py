#coding=utf-8

T = int(raw_input())

def solve(limits):
    res = ''
    pre_a, pre_b = 0, 0
    p = 0
    stops = 'xyz'
    cur = 'a'
    for i, (a, b) in enumerate(limits):
        diff_a = a - pre_a
        diff_b = b - pre_b
        pre_a, pre_b = a, b
        a, b = diff_a, diff_b

        if a < b:
            return ''

        if i == 0:
            res += 'a' * (b - 3)
            a -= len(res)
        else:
            res += cur * b
            a -= b

        while a:
            res += stops[p]
            p = (p + 1) % len(stops)
            a -= 1

        cur = chr(ord(cur) + 1)

    return res



for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    A = map(int, raw_input().split())
    B = map(int, raw_input().split())

    limits = sorted(zip(A, B))
    res = solve(limits)

    if not res:
        print 'NO'
    else:
        print 'YES'
        print res

'''
^^^^TEST^^^
7
10 2
5 10
5 6
3 1
3
3
4 2
3 4
3 3
4 2
3 4
3 4
4 1
4
5
10 3
4 6 10
4 5 8
10 4
4 6 7 10
4 5 7 8
----------
YES
abcbbcabcb
YES
foo
YES
ayda
YES
wada
NO
YES
abcbcacbab
NO
$$$TEST$$$$

^^^^TEST^^^
1
200000 3
64462 134770 200000
60049 111899 135119
--------
<ignore>
$$$$$$TEST$$$$
'''

