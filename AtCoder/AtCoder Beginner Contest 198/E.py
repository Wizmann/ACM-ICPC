import sys

sys.setrecursionlimit(10000000)

from collections import defaultdict

g = defaultdict(list)

n = int(raw_input())
cs = [0] + map(int, raw_input().split())

for i in xrange(n - 1):
    a, b = map(int, raw_input().split())
    g[a].append(b)
    g[b].append(a)

dp = defaultdict(int)
ans = []

def dfs(pre, cur, d):
    global ans
    if dp[cs[cur]] == 0:
        ans.append(cur)
    dp[cs[cur]] += 1
    for nxt in g[cur]:
        if nxt == pre:
            continue
        dfs(cur, nxt, d)
    dp[cs[cur]] -= 1

dfs(-1, 1, dp)
ans.sort()
print '\n'.join(map(str, ans))

'''
^^^TEST^^^
6
2 7 1 8 2 8
1 2
3 6
3 2
4 3
2 5
----
1
2
3
4
6
$$$TEST$$$

^^^TEST^^^
10
3 1 4 1 5 9 2 6 5 3
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
---
1
2
3
5
6
7
8
$$$TEST$$$


'''
