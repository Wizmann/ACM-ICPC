INF = 10 ** 10

class Solution(object):
    def surfaceArea(self, grids):
        st = set()
        for i in xrange(len(grids)):
            for j in xrange(len(grids[i])):
                for k in xrange(grids[i][j]):
                    st.add((i, j, k))
        mv = [
            [-1, 0, 0],
            [1, 0, 0],
            [0, -1, 0],
            [0, 1, 0],
            [0, 0, -1],
            [0, 0, 1]
        ]
        res = 0
        for i in xrange(len(grids)):
            for j in xrange(len(grids[i])):
                for k in xrange(grids[i][j]):
                    for (dx, dy, dz) in mv:
                        if (i + dx, j + dy, k + dz) not in st:
                            res += 1

        return res

