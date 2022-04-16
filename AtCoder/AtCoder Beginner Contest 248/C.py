MOD = 998244353

d = {}

def dfs(n, m, k):
    if n == 0:
        assert k >= 0
        return 1
    key = (n, m, k)
    if key in d:
        return d[key]

    res = 0
    for i in xrange(1, m + 1):
        if k - i >= 0:
            res += dfs(n - 1, m, k - i)
            res %= MOD
    d[key] = res
    return res

(n, m, k) = map(int, raw_input().split())

print dfs(n, m, k) % MOD

'''
^^^^TEST^^^^
2 3 4
------
6
$$$TEST$$$$



^^^^TEST^^^^
31 41 592
------
798416518
$$$TEST$$$$

'''
