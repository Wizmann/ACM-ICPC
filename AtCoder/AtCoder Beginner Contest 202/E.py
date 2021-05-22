#coding=utf-8
import sys
sys.setrecursionlimit(1234567)

from collections import defaultdict

n = int(raw_input())

g = defaultdict(list)
queries = defaultdict(list)

ps = map(int, raw_input().split())
for i in xrange(n - 1):
    cur = 2 + i
    pre = ps[i]

    g[pre].append(cur)
    g[cur].append(pre)

q = int(raw_input())

for i in xrange(q):
    u, d = map(int, raw_input().split())
    queries[u].append((d, i))

ans = [0 for i in xrange(q)]

def dfs2(pre, cur, d, path):
    for (q, idx) in queries[cur]:
        ans[idx] -= path[q]

    for nxt in g[cur]:
        if nxt == pre:
            continue
        dfs2(cur, nxt, d + 1, path)

    path[d] += 1

    for (q, idx) in queries[cur]:
        ans[idx] += path[q]

dfs2(-1, 1, 0, defaultdict(int))

for item in ans:
    print item

'''
^^^TEST^^^
7
1 1 2 2 4 2
4
1 2
7 2
4 1
5 5
------
3
1
0
0
$$$TEST$$$

^^^TEST^^^
7
1 1 2 2 4 2
4
2 3
3 3
2 1
4 3
------
1
0
1
1
$$$TEST$$$
'''


