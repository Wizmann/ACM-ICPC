#coding=utf-8

INF = 10 ** 100

class Solution(object):
    def paintWalls(self, cost, time):
        n = len(cost)
        dp = {0: 0}
        res = INF
        jobs = list(zip(cost, time))
        jobs.sort(key=lambda x: (-x[1], x[0]))
        for i, (c, t) in enumerate(jobs):
            for (dt, cc) in dp.items():
                nxt_c = cc + c
                nxt_dt = dt + 1 + t

                if nxt_c >= res:
                    continue

                if nxt_dt >= n:
                    res = min(res, nxt_c)
                    continue

                dp[nxt_dt] = min(dp.get(nxt_dt, INF), nxt_c)

        return res


'''
^^^^TEST^^^^
[1,2,3,2]
[1,2,3,2]
------------
3
$$$$TEST$$$$

^^^^TEST^^^^
[2,3,4,2]
[1,1,1,1]
------------
4
$$$$TEST$$$$

^^^^TEST^^^^
[42,8,28,35,21,13,21,35]
[2,1,1,1,2,1,1,2]
------------
63
$$$$TEST$$$$
'''

