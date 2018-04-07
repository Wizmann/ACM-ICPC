import sys


INF = 10 ** 10
N = 12345

def solve(n, ns):
    assert sum(ns) < N
    dp = [0 for i in xrange(N)]
    dp[0] = 1

    for num in ns:
        for i in xrange(N - 1, -1, -1):
            if dp[i] and i + num < N:
                dp[i + num] = 1
    s = sum(ns)

    ans = INF
    for i in xrange(N):
        if dp[i]:
            ans = min(ans, abs(s - 2 * i))
    return ans

if __name__ == '__main__':
    n = int(raw_input())
    if n == 0:
        print 0
    else:
        ns = map(int, raw_input().split())
        print solve(n, ns)
