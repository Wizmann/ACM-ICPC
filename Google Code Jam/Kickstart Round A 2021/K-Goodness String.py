def solve(s, k):
    n = len(s)
    l, r = 0, n - 1
    score = 0
    while l < r:
        if s[l] != s[r]:
            score += 1
        l += 1
        r -= 1
    return abs(score - k)


T = int(raw_input())

for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    s = raw_input()

    print 'Case #%d: %d' % (case_ + 1, solve(s, k))

'''
^^^TEST^^^
2
5 1
ABCAA
4 2
ABAA
----
Case #1: 0
Case #2: 1
$$$TEST$$$
'''
