INF = 10 ** 10

class Solution(object):
    def waysToBuyPensPencils(self, total, cost1, cost2):
        res = 0
        for i in xrange(INF):
            if cost1 * i > total:
                break
            res += (total - cost1 * i + cost2) / cost2
        return res
