INF = 10 ** 10

class Solution(object):
    def maximumBeauty(self, items, queries):
        d = {}
        for (price, beauty) in items:
            d[price] = max(beauty, d.get(price, -INF))
        items = d.items()
        items.sort()
        
        n = len(items)
        maxi = -INF
        for i in xrange(n):
            maxi = max(maxi, items[i][1])
            items[i] = (items[i][0], maxi)
        
        res = []
        for q in queries:
            l, r = 0, n - 1
            while l <= r:
                m = (l + r) / 2
                if items[m][0] > q:
                    r = m - 1
                else:
                    l = m + 1

            if r == -1:
                res.append(0)
            else:
                res.append(items[r][1])
        return res
