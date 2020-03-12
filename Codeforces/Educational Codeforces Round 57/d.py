n = int(raw_input())
s = raw_input()
vs = map(int, raw_input().split())

dp = [0, 0, 0, 0]
for v, c in zip(vs, s):
    if c == 'h':
        dp[1] = min(dp[1], dp[0])
        dp[0] += v
    elif c == 'a':
        dp[2] = min(dp[1], dp[2])
        dp[1] += v
    elif c == 'r':
        dp[3] = min(dp[2], dp[3])
        dp[2] += v
    elif c == 'd':
        dp[3] += v
print min(dp)
