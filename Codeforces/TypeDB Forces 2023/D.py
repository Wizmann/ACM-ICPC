INF = 10 ** 100

import sys
sys.setrecursionlimit(12345)
from collections import defaultdict

class Solution(object):
    def __init__(self, n, ns):
        self.n = n
        self.ns = ns

    def solve(self):
        cur = 0
        has_loop = False
        self.path = {}
        step = 0
        while 0 <= cur < self.n:
            if cur in self.path:
                has_loop = True
                break
            self.path[cur] = step
            step += 1
            cur = cur + self.ns[cur]

        m = len(self.path)
        # print self.path, has_loop

        tot = m * (self.n + 1)
        if not has_loop:
            tot += (self.n - m) * (2 * self.n + 1)
        # print tot

        self.dest = {}
        self.visited = set()
        for i in xrange(self.n):
            if i in self.path:
                continue
            nxt = self.dfs(i)
            # print i, nxt
            if nxt in [-INF, INF]:
                tot += m
            elif nxt in self.path:
                if not has_loop:
                    idx = self.path[nxt]
                    tot += idx

        if not has_loop:
            tot += (m - 1) * m / 2

        return tot

    def dfs(self, cur):
        if cur in self.path:
            return cur

        if cur in self.dest:
            return self.dest[cur]

        if cur in self.visited:
            return cur

        self.visited.add(cur)

        nxt = cur + self.ns[cur]
        if nxt < 0:
            self.dest[cur] = -INF
        elif nxt >= self.n:
            self.dest[cur] = INF
        else:
            self.dest[cur] = self.dfs(nxt)

        return self.dest[cur]


T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())

    # print n
    # print ns

    print Solution(n, ns).solve()


'''
^^^TEST^^^^
1
2
0 -2
----------
4
$$$TEST$$$

^^^^TEST^^^
1
2
-1 0
----------------
8
$$$TEST$$$

^^^^TEST^^^
1
3
1 -2 -1
----------------
17
$$$TEST$$$

^^^^TEST^^^
1
2
1 1
----------------
7
$$$TEST$$$

^^^TEST^^^^
9
1
0
2
-1 0
2
1 -1
2
1 1
3
-1 -2 -1
3
1 -2 -1
4
-1 4 -2 1
5
1 1 1 1 -4
5
1 1 1 1 1
------------
2
8
6
7
20
17
34
30
40
$$$TEST$$$

'''


