n = int(input())
ns = list(map(int, input().split()))

INF = 0x3f3f3f3f

dp = [INF for i in range(n)]
dp[0] = 0
ns[-1] = 0

for i in range(1, n):
    if ns[i] == 1:
        continue
    if i - 1 >= 0 and ns[i - 1] == 0:
        dp[i] = min(dp[i], dp[i - 1] + 1)
    if i - 2 >= 0 and ns[i - 2] == 0:
        dp[i] = min(dp[i], dp[i - 2] + 1)
print(dp[-1])
