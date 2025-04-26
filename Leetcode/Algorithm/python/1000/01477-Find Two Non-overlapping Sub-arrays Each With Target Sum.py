INF = 10 ** 10

class Solution(object):
    def minSumOfLengths(self, arr, target):
        n = len(arr)
        dp1 = [INF for i in xrange(n)]
        d = {0: -1}
        pre = 0
        for i in xrange(n):
            pre += arr[i]
            u = pre - target
            if u in d:
                dp1[i] = i - d[u]
            d[pre] = i
        
        d = {0: n}
        dp2 = [INF for i in xrange(n)]
        pre = 0
        for i in xrange(n - 1, -1, -1):
            pre += arr[i]
            u = pre - target
            if u in d:
                dp2[i] = d[u] - i
            d[pre] = i
        dp3 = [INF for i in xrange(n)]
        
        for i in xrange(1, n):
            dp1[i] = min(dp1[i - 1], dp1[i])
        for i in xrange(n - 2, -1, -1):
            dp2[i] = min(dp2[i], dp2[i + 1])
        # print dp1, dp2
        res = INF
        for i in xrange(n - 1):
            res = min(res, dp1[i] + dp2[i + 1])
        if res >= INF:
            res = -1
        return res
        
