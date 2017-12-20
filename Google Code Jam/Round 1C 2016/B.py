class Solution1(object):
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
                return g

        return None

class Solution2(object):
    def __init__(self, b, m):
        self.b = b
        self.m = m

    def log2(self, n):
        cnt = 0
        while n:
            cnt += 1
            n >>= 1
        return cnt

    def solve(self):
        if self.m > (1 << (self.b - 2)):
            return None

        mat = [ [0 for i in xrange(self.b) ] for j in xrange(self.b)]

        l = self.log2(self.m)
        for i in xrange(l):
            for j in xrange(i + 1, l):
                mat[i][j] = 1
            mat[i][self.b - 1] = 1

        self.m -= (1 << (l - 1))
        if self.m:
            mat[l][self.b - 1] = 1

        for i in xrange(1, self.b):
            if self.m & (1 << (i - 1)):
                mat[i][l] = 1

        return mat

def test():
    for i in xrange(2, 6):
        for j in xrange(1, 25):
            S1 = Solution1(i, j)
            S2 = Solution2(i, j)

            ans = S2.solve()
            print i, j, ans
            if not ans:
                assert S1.solve() == None
            else:
                print S1.dfs(ans, 0)
                assert S1.dfs(ans, 0) == j


if __name__ == '__main__':
    from multiprocessing import Pool
    p = Pool(10)

    T = int(raw_input())
    queries = [map(int, raw_input().split()) for i in xrange(T)]

    ans = p.map(lambda (x, y): Solution2(x, y).solve(), queries)

    for i, mat in enumerate(ans):
        print 'Case #%d: %s' % (i + 1, 'POSSIBLE' if mat else 'IMPOSSIBLE')
        if mat:
            for line in mat:
                print ''.join(map(str, line))
