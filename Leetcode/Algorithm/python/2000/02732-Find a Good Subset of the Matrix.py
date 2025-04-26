from collections import defaultdict

class Solution(object):
    def goodSubsetofBinaryMatrix(self, grid):
        n = len(grid)
        m = len(grid[0])

        d = {}

        for i in xrange(n):
            key = int(''.join(map(str, grid[i])), 2)
            if key == 0:
                return [i]
            if key not in d:
                d[key] = i

        for (k1, v1) in d.items():
            for (k2, v2) in d.items():
                if k1 & k2 == 0:
                    return sorted([v1, v2])

        return []
'''
^^^^TEST^^^^
[[0,1,1,0],[0,0,0,1],[1,1,1,1]]
----------------
[0, 1]
$$$$TEST$$$$

^^^^TEST^^^^
[[0,0],[1,1],[1,0],[1,0]]
----------------
[0]
$$$$TEST$$$$
'''


