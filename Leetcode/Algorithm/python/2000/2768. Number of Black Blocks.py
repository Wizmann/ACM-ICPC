from collections import defaultdict

class Solution(object):
    def countBlackBlocks(self, n, m, coordinates):
        mv = {
            (-1, -1): 3,
            (-1, 0) : 2,
            (0, -1) : 1,
            (0, 0)  : 0,
        }

        d = defaultdict(int)

        for (y, x) in coordinates:
            for (dy, dx), k in mv.items():
                ny = y + dy
                nx = x + dx
                if 0 <= ny and ny + 1 < n and 0 <= nx and nx + 1 < m:
                    d[(ny, nx)] += 1
        res = [(m - 1) * (n - 1), 0, 0, 0, 0]

        for (_, value) in d.items():
            res[0] -= 1
            res[value] += 1
        return res


'''
^^^^TEST^^^
3
3
[[0,0]]
-------
[3,1,0,0,0]
$$$$TEST$$$$

^^^^TEST^^^
3
3
[[0,0],[1,1],[0,2]]
-------
[0,2,2,0,0]
$$$$TEST$$$$
'''
