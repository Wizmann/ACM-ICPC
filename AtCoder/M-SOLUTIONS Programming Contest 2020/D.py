INF = 10 ** 10

def solve(ns):
    n = len(ns)
    dp = [ set([(1000, 0)]), set([]) ]
    p = 0
    for price in ns:
        q = p ^ 1
        dp[q] = set()
        for (money, stock) in dp[p]:
            m1 = money + stock * price
            dp[q].add((m1, 0))
            m2 = money % price
            s2 = stock + money / price
            dp[q].add((m2, s2))
            dp[q].add((money, stock))
        p = q
    maxi = -INF
    for (money, stock) in dp[p]:
        maxi = max(maxi, money)
    return maxi

def solve2(ns):
    n = len(ns)
    dp = [1000] + [-INF for i in xrange(n)]
    for i in xrange(1, n + 1):
        for j in xrange(i + 1, n + 1):
            if ns[j - 1] <= ns[i - 1]:
                continue
            money = dp[i - 1]

            # buy in day[i]
            stock = money / ns[i - 1]
            money = money % ns[i - 1]

            # sell in day[j]
            money = money + stock * ns[j - 1]
            stock = 0

            dp[j] = max(dp[j], money)
        dp[i] = max(dp[i], dp[i - 1])
    return max(dp)

assert solve2([200, 188, 181, 115, 160]) == 1360
assert solve2([200, 180, 160, 140, 120, 100]) == 1000
assert solve2([100, 130, 130, 130, 115, 115, 150]) == 1685
# assert solve([200, 180, 160, 140, 120, 100]) == 1000
assert solve2([157, 193]) == 1216

n = int(raw_input())
ns = map(int, raw_input().split())

# print solve(ns[:])
print solve2(ns[:])
