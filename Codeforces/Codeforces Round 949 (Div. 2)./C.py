INF = 10 ** 100

def do_solve(ns, l, r):
    if ns[l] == INF:
        cur = r - 1
        if ns[r] == INF:
            ns[r] = 1
        flip = 1
        while cur >= l:
            if flip:
                ns[cur] = ns[cur + 1] * 2
            else:
                ns[cur] = ns[cur + 1] / 2
            cur -= 1
            flip ^= 1
        return True
    elif ns[r] == INF:
        cur = l + 1
        flip = 1
        while cur <= r:
            if flip:
                ns[cur] = ns[cur - 1] * 2
            else:
                ns[cur] = ns[cur - 1] / 2
            cur += 1
            flip ^= 1
        return True
    else:
        # print l, r, ns[l: r + 1]
        ll, rr = l, r
        flip = 0
        if ns[l] < ns[r]:
            flip = 1
            ns[l], ns[r] = ns[r], ns[l]

        steps = 0
        a, b = ns[l], ns[r]
        cur = l + 1
        while cur < r:
            if a.bit_length() > b.bit_length():
                a /= 2
                ns[cur] = a
            else:
                shift = b.bit_length() - a.bit_length()
                bb = b >> shift
                if a != bb:
                    a /= 2
                    ns[cur] = a
                elif shift == 0:
                    ns[cur] = b << 1
                    a = ns[cur]
                else:
                    ns[cur] = b >> (shift - 1)
                    a = ns[cur]
            cur += 1

        l, r = ll, rr
        if flip:
            while l <= r:
                ns[l], ns[r] = ns[r], ns[l]
                l += 1
                r -= 1

        l, r = ll, rr
        # print l, r, ns[l: r + 1]
        for i in xrange(l + 1, r):
            a, b = ns[i - 1], ns[i]
            # print a, b
            if not (a == b / 2 or b == a / 2):
                return False

        return True


def solve(ns):
    n = len(ns)
    pre = -1
    for i in xrange(n):
        if ns[i] != -1:
            if pre != -1:
                flag = do_solve(ns, pre, i)
                if not flag:
                    return [-1]
            pre = i

    for i in xrange(2, len(ns) - 1):
        a, b = ns[i - 1], ns[i]
        # print a, b
        if not (a == b / 2 or b == a / 2):
            return [-1]

    return ns

T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())
    assert n == len(ns)

    ns = [INF] + ns + [INF]

    res = solve(ns)

    if res == [-1]:
        print -1
    else:
        print ' '.join(map(str, ns[1: -1]))
        for i in xrange(2, n + 1):
            a, b = ns[i - 1], ns[i]
            assert a == b / 2 or b == a / 2

'''
^^^^^TEST^^^^^
9
8
-1 -1 -1 2 -1 -1 1 -1
4
-1 -1 -1 -1
6
3 -1 -1 -1 9 -1
4
-1 5 -1 6
4
2 -1 -1 3
4
1 2 3 4
2
4 2
5
-1 3 -1 3 6
13
-1 -1 3 -1 -1 -1 -1 7 -1 -1 3 -1 -1
-------------
4 9 4 2 4 2 1 2
7 3 6 13
3 1 2 4 9 18
-1
-1
-1
4 2
6 3 1 3 6
3 1 3 1 3 7 3 7 3 1 3 1 3
$$$$$TEST$$$$$
'''

 
