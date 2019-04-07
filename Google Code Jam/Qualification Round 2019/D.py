import sys

def detect(resp, base, n):
    st = set(resp)
    res = []
    for i in xrange(n):
        if i not in st:
            res.append(base + i)
    return res

T = int(raw_input())

for case_ in xrange(T):
    n, b, f = map(int, raw_input().split())
    m = n - b

    resp = [0 for i in xrange(m)]
    for i in xrange(5):
        q = ''
        for j in xrange(n):
            u = j % 32
            q += '{:05b}'.format(u)[i]
        print q
        sys.stdout.flush()
        r = map(int, str(raw_input()))
        for j in xrange(m):
            resp[j] |= r[j] << (4 - i)

    res = []
    l, r = 0, 0
    base = 0
    pre = 10 ** 10
    resp.append(-1)
    for i in xrange(m + 1):
        if resp[i] < pre:
            if i == 0:
                l, r = 0, 0
            else:
                r = i
                res += detect(resp[l: r], base, min(n - base, 32))
                base += 32
                l = i
        pre = resp[i]

    print ' '.join(map(str, res))

    sys.stdout.flush()
    verdict = raw_input()

