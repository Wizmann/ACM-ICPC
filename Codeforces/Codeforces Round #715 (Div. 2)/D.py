def do_solve(n, p1, p2, v):
    res = []
    it1, it2 = 0, 0
    # print p1, p2, v
    while it1 < len(p1) and it2 < len(p2):
        if p1[it1] == v and p2[it2] == v:
            res.append(v)
            it1 += 1
            it2 += 1
        elif p1[it1] != v:
            res.append(p1[it1])
            it1 += 1
        else:
            res.append(p2[it2])
            it2 += 1
    # print '---'

    # print it1, it2, res
    while it1 < len(p1):
        res.append(p1[it1])
        it1 += 1

    while it2 < len(p2):
        res.append(p2[it2])
        it2 += 1

    res = ''.join(map(str, res))
    assert len(res) <= 3 * n
    return res


def solve(n, ps):
    ones = []
    zeros = []
    for i in xrange(3):
        cnt0, cnt1 = 0, 0
        for c in ps[i]:
            if c == 0:
                cnt0 += 1
            else:
                cnt1 += 1
        zeros.append(cnt0)
        ones.append(cnt1)

    for i in xrange(3):
        for j in xrange(i + 1, 3):
            if min(ones[i], ones[j]) >= n:
                return do_solve(n, ps[i], ps[j], 1)
            if min(zeros[i], zeros[j]) >= n:
                return do_solve(n, ps[i], ps[j], 0)
    assert False

T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ps = []
    for i in xrange(3):
        ps.append(map(int, raw_input()))

    print solve(n, ps)

'''

^^^TEST^^^
2
1
00
11
01
3
011001
111010
010001
----
010
011001010
$$$TEST$$$

'''

