from collections import defaultdict

MAXN = 123456

class Solution(object):
    def countServers(self, n, logs, x, queries):
        logs.sort(key=lambda x: x[1])
        queries = sorted(enumerate(queries), key=lambda x: x[1])
        q = len(queries)
        m = len(logs)

        d = {}
        p1, p2 = 0, 0

        res = [0 for i in xrange(q)]
        for (idx, r) in queries:
            l = r - x
            while p2 < m:
                sid, pos = logs[p2]
                if pos <= r:
                    d[sid] = d.get(sid, 0) + 1
                    p2 += 1
                else:
                    break
            while p1 < p2:
                sid, pos = logs[p1]
                if pos < l:
                    d[sid] -= 1
                    if d[sid] == 0:
                        del d[sid]
                    p1 += 1
                else:
                    break
            res[idx] = n - len(d)
        return res


'''
^^^^TEST^^^^
3
[[1,3],[2,6],[1,5]]
5
[10,11]
----------------
[1, 2]
$$$TEST$$$$

^^^^TEST^^^^
3
[[2,4],[2,1],[1,2],[3,1]]
2
[3,4]
------
[0,1]
$$$TEST$$$$

^^^^TEST^^^^
6
[[1,21]]
10
[24,35,28,26,20,25,16,31,12]
------
[5,6,5,5,6,5,6,5,6]
$$$TEST$$$$
'''


