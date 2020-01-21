from collections import defaultdict

INF = 10 ** 10

class Solution(object):
    def minTaps(self, n, ranges):
        rs = []
        d = defaultdict(int)
        for i, r in enumerate(ranges):
            l = max(0, i - r)
            r = min(n, i + r)
            d[l] = max(d[l], r)
        for k, v in d.items():
            rs.append((k, v))
        rs.sort()
        rs.append((n, n))
        res = 0
        pre = 0
        maxi = -1
        for (l, r) in rs:
            if l > pre:
                res += 1
                pre = maxi
                maxi = -1
            #print l, r, pre, res
            if l > pre:
                break
                
            if pre == n:
                break
                
            maxi = max(maxi, r)
        if pre != n:
            return -1
        return res
