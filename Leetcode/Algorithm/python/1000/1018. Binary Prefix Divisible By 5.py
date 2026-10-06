class Solution(object):
    def prefixesDivBy5(self, A):
        res = []
        cur = 0
        for a in A:
            cur = cur * 2 + a
            res.append(cur % 5 == 0)
        return res
