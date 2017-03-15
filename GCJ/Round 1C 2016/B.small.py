class Solution(object):
    def __init__(self, b, m):
        self.b = b
        self.m = m
        self.visit = [0 for i in xrange(self.b)]

    def fast_test_g(self, g):
        for i in xrange(self.b):
            for j in xrange(self.b):
                if g[i][j] and g[j][i]:
                    return False

        return True

    def make_g(self, mark):
        g = [
                [0 for i in xrange(self.b)]
                for j in xrange(self.b)
        ]

        for i in xrange(self.b):
            for j in xrange(self.b):
                if i == j:
                    continue
                g[i][j] = mark & 1
                mark >>= 1
        return g

    def dfs(self, g, cur):
        if self.visit[cur]:
            return -1

        if cur == self.b - 1:
            return 1
        self.visit[cur] = 1

        res = 0
        for i, cnc in enumerate(g[cur]):
            if not cnc:
                continue
            t = self.dfs(g, i)
            if t == -1:
                return -1
            res += t

        self.visit[cur] = 0
        return res

    def solve(self):
        k = (self.b - 1) * self.b - (self.b - 1)
        for i in xrange(1 << k):
            g = self.make_g(i)

            if not self.fast_test_g(g):
                continue

            self.visit = [0 for i in xrange(self.b)]
            path_cnt = self.dfs(g, 0)

            if path_cnt == self.m:
                print g
                return g

        return None

if __name__ == '__main__':
    from multiprocessing import Pool
    p = Pool(10)

    T = int(raw_input())
    queries = [map(int, raw_input().split()) for i in xrange(T)]

    ans = p.map(lambda (x, y): Solution(x, y).solve(), queries)

    for i, mat in enumerate(ans):
        print 'Case #%d: %s' % (i + 1, 'POSSIBLE' if mat else 'IMPOSSIBLE')
        if mat:
            for line in mat:
                print ''.join(map(str, line))
