INF = 10 ** 10


class BIT2D(object):
    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.tree = [[0] * (m + 1) for _ in xrange(n + 1)]

    def add(self, y, x, delta):
        i = y + 1
        while i <= self.n:
            j = x + 1
            row = self.tree[i]
            while j <= self.m:
                row[j] += delta
                j += j & -j
            i += i & -i

    def _sum(self, y, x):
        if y < 0 or x < 0:
            return 0
        if y >= self.n:
            y = self.n - 1
        if x >= self.m:
            x = self.m - 1

        res = 0
        i = y + 1
        while i > 0:
            j = x + 1
            row = self.tree[i]
            while j > 0:
                res += row[j]
                j -= j & -j
            i -= i & -i
        return res

    def query(self, y1, x1, y2, x2):
        if y1 > y2 or x1 > x2:
            return 0
        y1 = max(y1, 0)
        x1 = max(x1, 0)
        y2 = min(y2, self.n - 1)
        x2 = min(x2, self.m - 1)
        if y1 > y2 or x1 > x2:
            return 0
        return (self._sum(y2, x2) - self._sum(y1 - 1, x2) -
                self._sum(y2, x1 - 1) + self._sum(y1 - 1, x1 - 1))


class Solution(object):
    def countLocalMaximums(self, matrix):
        n = len(matrix)
        m = len(matrix[0])

        ps = []
        for i in xrange(n):
            for j in xrange(m):
                ps.append((matrix[i][j], i, j))

        ps.sort(reverse=True)
        bit = BIT2D(n, m)
        res = 0
        i = 0
        cnt = len(ps)

        while i < cnt:
            v = ps[i][0]
            if v == 0:
                break

            j = i
            while j < cnt and ps[j][0] == v:
                j += 1

            if v < 0:
                res += cnt - i
                break

            for _, y, x in ps[i:j]:
                total = bit.query(y - v, x - v, y + v, x + v)
                total -= bit.query(y - v, x - v, y - v, x - v)
                total -= bit.query(y - v, x + v, y - v, x + v)
                total -= bit.query(y + v, x - v, y + v, x - v)
                total -= bit.query(y + v, x + v, y + v, x + v)
                if total == 0:
                    res += 1

            for _, y, x in ps[i:j]:
                bit.add(y, x, 1)

            i = j

        return res
