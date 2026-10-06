class Solution(object):
    def findKthNumber(self, n, k):
        return self.dfs(1, k, n)

    def sumup(self, l):
        return ((10 ** (l + 1)) - 1) / 9

    def dfs(self, prefix, k, n):
        if k == 1:
            return prefix

        l = len(str(n))
        lp = len(str(prefix))
        ls = l - lp

        nprefix = int(str(n)[:lp])
        nsuffix = -1 if ls == 0 else int(str(n)[lp:])

        if nprefix > prefix:
            kk = self.sumup(ls)
        elif nprefix == prefix:
            assert ls != 0
            kk = nsuffix + 1 + self.sumup(ls - 1)
        else:
            kk = self.sumup(ls - 1)

        if k > kk:
            return self.dfs(prefix + 1, k - kk, n)
        else:
            return self.dfs(prefix * 10, k - 1, n)

def test():
    S = Solution()
    ns = [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]
    for i in xrange(13):
        assert S.findKthNumber(13, i + 1) == ns[i]

    import random

    for i in xrange(100):
        n = random.randint(20, 1000)
        ns = map(int,
                sorted(
                    map(str, range(1, n + 1))
                )
            )
        print ns
        for i in xrange(n):
            assert S.findKthNumber(n, i + 1) == ns[i]
            print 'ok', i

    

test()
