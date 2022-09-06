import sys

INF = 10 ** 10

def solve(n, ns):
    dp1, dp2 = [{} for i in xrange(n)], [{} for i in xrange(n)]

    ans = 2
    for i in xrange(n):
        if i - 1 >= 0:
            diff = ns[i - 1] - ns[i]
            dp1[i][diff] = 2
            if diff in dp1[i - 1]:
                dp1[i][diff] = dp1[i - 1][diff] + 1
            for (key, value) in dp1[i - 1].items():
                ans = max(ans, value + 1)

    for i in xrange(n - 1, -1, -1):
        if i + 1 < n:
            diff = ns[i] - ns[i + 1]
            dp2[i][diff] = 2
            if diff in dp2[i + 1]:
                dp2[i][diff] = dp2[i + 1][diff] + 1
            for (key, value) in dp2[i + 1].items():
                ans = max(ans, value + 1)

    for i in xrange(1, n - 1):
        pre = ns[i - 1]
        cur = ns[i]
        nxt = ns[i + 1]

        diff = pre - nxt
        if diff % 2 != 0:
            continue
        ans = max(ans, 3)
        diff /= 2
        u = dp1[i - 1].get(diff, 1) + 1 + dp2[i + 1].get(diff, 1)
        ans = max(ans, u)
    return ans

T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())
    print 'Case #%d: %d' % (case_ + 1, solve(n, ns))

'''

^^^TEST^^^
3
4
9 7 5 3
9
5 5 4 5 5 5 4 5 6
4
8 5 2 0
----
Case #1: 4
Case #2: 6
Case #3: 4
$$$TEST$$$

^^^TEST^^^
5
3
1 2 3
3
1 5 3
3
999 2 3
3
1 2 999
2
123 899
----
Case #1: 3
Case #2: 3
Case #3: 3
Case #4: 3
Case #5: 2
$$$TEST$$$


'''


