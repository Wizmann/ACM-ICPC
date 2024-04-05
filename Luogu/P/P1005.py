#coding=utf-8

def dfs(dp, ns, l, r):
    if l == r:
        return ns[l]
    key = (l, r)
    if key in dp:
        return dp[key]
    cur = 0
    cur = max(cur, dfs(dp, ns, l + 1, r) * 2 + ns[l])
    cur = max(cur, dfs(dp, ns, l, r - 1) * 2 + ns[r])
    dp[key] = cur
    return cur


(n, m) = map(int, raw_input().split())

tot = 0
for i in xrange(n):
    ns = map(int, raw_input().split())
    dp = {}
    cur = dfs(dp, ns, 0, m - 1) * 2
    tot += cur

print tot

'''
^^^TEST^^^
2 3
1 2 3
3 4 2
---
82
$$$TEST$$$
'''

