import sys
sys.setrecursionlimit(5566655)

n = int(raw_input())

A = map(int, raw_input().split())
B = map(int, raw_input().split())
C = map(int, raw_input().split())

dp = [ [-1 for i in xrange(n)] for j in xrange(2) ]

def dfs(cur, flag):
    if cur == n - 1:
        return B[cur] if flag else A[cur]

    if dp[flag][cur] != -1:
        return dp[flag][cur]

    a = dfs(cur + 1, True)
    b = dfs(cur + 1, False)

    res = max(a + (B[cur] if flag else A[cur]),
              b + (C[cur] if flag else B[cur]))

    dp[flag][cur] = res
    return res

print dfs(0, False)
