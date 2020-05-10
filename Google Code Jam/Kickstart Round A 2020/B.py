
INF = 10 ** 10

T = int(raw_input())

for case_ in xrange(T):
    (n, k, p) = map(int, raw_input().split())
    s = []

    for i in xrange(n):
        s.append(map(int, raw_input().split()))


    dp = [0] + [-INF for i in xrange(p)]

    for i in xrange(n):
        prefix = 0
        prefixs = []
        for j, num in enumerate(s[i]):
            prefix += num
            prefixs.append(prefix)

        for j in xrange(p, -1, -1):
            if dp[j] == -INF:
                continue
            for k, prefix in enumerate(prefixs):
                if j + k + 1 <= p:
                    dp[j + k + 1] = max(dp[j + k + 1], dp[j] + prefix);
    print 'Case #%d: %d' % (case_ + 1, dp[p])
