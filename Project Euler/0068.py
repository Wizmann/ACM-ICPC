import sys
import itertools

INF = 10 ** 10

ans = ''
for i in xrange(1 << 10):
    outter = []
    inner = []
    for j in xrange(10):
        if i & (1 << j):
            outter.append(j + 1)
        else:
            inner.append(j + 1)
    if len(outter) != 5:
        continue
    for perm0 in itertools.permutations(outter, len(outter)):
        if min(perm0) != perm0[0]:
            continue
        for perm1 in itertools.permutations(inner, len(inner)):
            s = set()
            res = []
            for j in xrange(5):
                a = perm0[j] + perm1[j] + perm1[(j + 1) % 5]
                res += [perm0[j], perm1[j], perm1[(j + 1) % 5]]
                s.add(a)
                if len(s) > 1:
                    break
            if len(s) == 1:
                print res
                ans = max(ans, ''.join(map(str, res)))
print ans
print len(ans)
