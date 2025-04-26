from collections import defaultdict

class Solution(object):
    def maximumImportance(self, n, roads):
        d = {}
        for i in xrange(n):
            d[i] = 0
        for (a, b) in roads:
            d[a] += 1
            d[b] += 1
        d = d.items()
        d.sort(key=lambda (idx, cnt): (cnt, idx))
        res = 0
        # print d
        for i in xrange(n):
            cnt = d[i][1]
            res += (i + 1) * cnt
        return res
