class Solution(object):
    def countPoints(self, points, queries):
        res = []
        for (y, x, r) in queries:
            cnt = 0
            for (py, px) in points:
                if (py - y) ** 2 + (px - x) ** 2 <= r * r:
                    cnt += 1
            res.append(cnt)
        return res

'''
^^^TEST^^^
[[1,3],[3,3],[5,3],[2,2]]
[[2,3,1],[4,3,1],[1,1,2]]
---------
[3, 2, 2]
$$$TEST$$$


^^^^TEST^^^
[[1,1],[2,2],[3,3],[4,4],[5,5]]
[[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
-------
[2,3,2,4]
$$$TEST$$$
'''

