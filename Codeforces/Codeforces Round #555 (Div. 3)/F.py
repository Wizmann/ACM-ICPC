from collections import Counter

INF = 10 ** 10

def solve(ns):
    c = Counter(ns)
    ms = sorted(c.items())
    ms.append((INF, 0))
    p, q = 0, 0
    tot = 0

    ss = sorted(c.items(), key=lambda x: x[1], reverse=True)
    maxi = ss[0][1]
    maxir = [ss[0][0], ss[0][0]]

    #print maxi, maxir

    while p < len(ms) and q < len(ms):
        num, cnt = ms[q]
        if cnt >= 2 and (p == q or ms[q][0] == ms[q - 1][0] + 1):
            q += 1
            tot += cnt
        else:
            tot += c[ms[p][0] - 1] + c[ms[q - 1][0] + 1]
            if tot > maxi:
                maxir = [ms[p][0] - 1, ms[q - 1][0] + 1]
                maxi = tot
            p = q + 1
            q = p
            tot = 0

    #print maxi, maxir
    res = [-1 for i in xrange(maxi)]
    l, r = 0, maxi - 1
    for i in xrange(maxir[0], maxir[1] + 1):
        if l == 0 and r == maxi - 1:
            for j in xrange(c[i]):
                res[l] = i
                l += 1
        elif c[i] >= 2:
            res[l] = i
            l += 1
            for j in xrange(c[i] - 1):
                res[r] = i
                r -= 1
        else:
            for j in xrange(c[i]):
                res[l] = i
                l += 1
    return res

n = int(raw_input())
ns = map(int, raw_input().split())

res = solve(ns)
print len(res)
print ' '.join(map(str, res))
