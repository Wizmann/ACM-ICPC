class Solution(object):
    def circularPermutation(self, n, start):
        ns = [0, 1]
        for i in xrange(n - 1):
            ns = ns + map(lambda x: x + (1 << (i + 1)), ns[::-1])
        idx = ns.index(start)
        res = []
        for i in xrange(2 ** n):
            res.append(ns[(idx + i) % (2 ** n)])
        return res
