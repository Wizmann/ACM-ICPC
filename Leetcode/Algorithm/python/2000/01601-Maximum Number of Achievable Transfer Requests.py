class Solution(object):
    def maximumRequests(self, n, requests):
        m = len(requests)
        res = 0
        for i in xrange(1 << m):
            ps = [0 for j in xrange(n)]
            tot = 0
            for j in xrange(m):
                if i & (1 << j):
                    a, b = requests[j]
                    ps[a] -= 1
                    ps[b] += 1
                    tot += 1
            if set(ps) == set([0]):
                res = max(res, tot)
        return res
