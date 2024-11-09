#python3
import math

INF = 10 ** 100
dp = {}

def dfs(n):
    if n == 0:
        return 0
    if n in dp:
        return dp[n]

    mini = n
    for i in range(int(math.sqrt(n) + 0.9), 0, -1):
        if i * i > n:
            continue
        mini = min(mini, dfs(n - i * i) + 1)
    dp[n] = mini
    return mini


n = int(input())

print(dfs(n))

