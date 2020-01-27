dp = {}
def brute_force(n):
    if n in dp:
        return dp[n]
    if n == 1:
        return 1
    maxi = 0
    for i in xrange(1, n):
        maxi = max(maxi, 1.0 * i / n + brute_force(n - i))
    dp[n] = maxi
    return maxi
 
def solve(n):
    res = 0
    for i in xrange(1, n + 1):
        res += 1.0 * 1 / i
    return res
 
for i in xrange(1, 100):
    #print i, solve(i), brute_force(i)
    assert solve(i) == brute_force(i)
 
n = int(raw_input())
print solve(n)
