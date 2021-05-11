T = int(raw_input())

def brute_force(L, R):
    cur = 1
    tot = 0
    while True:
        if L >= R:
            # print cur, L, R, 'L'
            if L >= cur:
                L -= cur
                tot += 1
            else:
                break
        else:
            # print cur, L, R, 'R'
            if R >= cur:
                R -= cur
                tot += 1
            else:
                break
        cur += 1
    return tot, L, R

# assert brute_force(15123, 10000)

def find_pivot(L, R):
    diff = abs(L - R)
    l, r = 0, diff
    while l <= r:
        m = (l + r) / 2
        tot = (1 + m) * m / 2
        if tot > diff:
            r = m - 1
        else:
            l = m + 1
    return r

assert find_pivot(1106, 1068) == 8
assert find_pivot(15123, 10000) == 100

def eliminate(pivot, L, R, m):
    lcnt = (m + 1) / 2
    rcnt = m / 2

    diff_l = (pivot + pivot + (lcnt - 1) * 2) * lcnt / 2
    diff_r = (pivot + 1 + pivot + 1 + (rcnt - 1) * 2) * rcnt / 2
    return diff_l, diff_r


def find_rem(pivot, L, R):
    assert L >= R
    
    l, r = 0, 10 ** 18
    while l <= r:
        m = (l + r) / 2

        diff_l, diff_r = eliminate(pivot, L, R, m)

        if diff_l > L or diff_r > R:
            r = m - 1
        else:
            l = m + 1
    res = r
    diff_l, diff_r = eliminate(pivot, L, R, res)

    # print res, L - diff_l, R - diff_r
    return res, L - diff_l, R - diff_r

#assert find_rem(3, 8, 8) == -1
assert find_rem(9, 1070, 1068)[0] == 56
assert find_rem(2, 1, 1) == (0, 1, 1)

def solve(L, R):
    swap = False
    if L < R:
        swap = True
        L, R = R, L
    assert L >= R

    pivot = find_pivot(L, R)

    # print 'pivot', pivot
    tot = pivot

    L -= (1 + pivot) * pivot / 2
    # print L, R
    if L == R:
        swap = False
    rem, ll, rr = find_rem(pivot + 1, L, R)
    # print ll, rr

    tot += rem
    if swap:
        ll, rr = rr, ll
    # print tot, ll, rr
    return tot, ll, rr

assert brute_force(8, 11) == (5, 0, 4)
assert brute_force(2, 2) == (2, 1, 0)
assert brute_force(1, 2) == (1, 1, 1)
assert solve(8, 11) == (5, 0, 4)
assert solve(1, 2) == (1, 1, 1)
assert solve(2, 2) == (2, 1, 0)


'''
from random import randint
for i in xrange(1000):
    a = randint(1, 10000)
    b = randint(1, 10000)
    # print a, b
    assert solve(a, b) == brute_force(a, b)
'''

assert brute_force(15123, 10000) == solve(15123, 10000)
    
for case_ in xrange(T):
    L, R = map(int, raw_input().split())
    a, b, c = solve(L, R)
    print 'Case #%d: %d %d %d' % (case_ + 1, a, b, c)
