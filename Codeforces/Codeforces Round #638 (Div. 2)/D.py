N = 64
def solve(n):
    res = []
    cur = 1
    while n > 0:
        # print n, cur
        n -= cur
        if n <= cur * 2:
            res.append(n - cur)
            n = 0
        elif n <= cur * 4:
            res.append(n / 2 - cur)
            cur += n / 2 - cur
        else:
            res.append(cur)
            cur *= 2
    # print res
    assert n == 0
    return res


def test(n):
    res = solve(n)
    assert min(res) >= 0
    mass = 1
    tot = 1
    for num in res:
        if num == 0:
            tot += mass
        else:
            mass += num
            tot += mass
    assert tot == n

test(10)
test(12)
test(5)
test(11)
test(4)

for i in xrange(2, 100):
    test(i)

test(10 ** 9)

T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    res = solve(n)
    print len(res)
    print ' '.join(map(str, res))
