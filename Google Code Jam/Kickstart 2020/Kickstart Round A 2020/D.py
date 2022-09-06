# REMEMBER TO ADD THE FUCKING `sys.setrecursionlimit(1234567)`

import sys
from collections import defaultdict

sys.setrecursionlimit(1234567)

def solve(strs, k, prefix=0):
    n = len(strs)
    d = defaultdict(list)

    for i in xrange(n):
        if prefix == len(strs[i]):
            d['$'].append(i)
        else:
            p = strs[i][prefix]
            d[p].append(strs[i])

    score, rem = 0, 0
    for key, value in d.items():
        if key == '$':
            rem += len(value)
        else:
            s, r = solve(value, k, prefix + 1)
            score += s
            rem += r

    score += (rem / k) * prefix
    rem = rem % k
    return score, rem

assert solve(["RAINBOW", "FIREBALL", "RANK", "RANDOM", "FIREWALL", "FIREFIGHTER"], 3) == (6, 0)
assert solve(["A", "AB", "ABC", "ABCD"], 2) == (4, 0)
assert solve(["KICK", "START"], 2) == (0, 0)


T = int(raw_input())

for case_ in xrange(T):
    (n, k) = map(int, raw_input().split())
    strs = []

    for i in xrange(n):
        strs.append(raw_input())

    strs.sort()

    score, _ = solve(strs, k)

    print 'Case #%d: %d' % (case_ + 1, score)
