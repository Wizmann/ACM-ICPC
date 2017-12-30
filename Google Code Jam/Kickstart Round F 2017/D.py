N = 111
M = 20
INF = 10 ** 10

def solve(s):
    dp = [INF for i in xrange(s + 1)]
    dp[0] = 0

    for i in xrange(N):
        u = i * i
        for j in xrange(M):
            v = u * (1 << j)
            if v > s:
                continue
            for k in xrange(s, -1, -1):
                if dp[k] >= INF:
                    continue
                if k + v > s:
                    continue

                dp[k + v] = min(dp[k + v], dp[k] + (1 << j))

    return dp[s]

assert solve(3) == 3
assert solve(4) == 1
assert solve(5) == 2

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        print 'Case #%d:' % (case_ + 1),

        s = int(raw_input())
        print solve(s)
