class Solution(object):
    def pancakeSort(self, A):
        n = len(A)
        res = []
        for i in xrange(n, 0, -1):
            u = A[:i + 1].index(i)
            if u != 0:
                res.append(u + 1)
                A[:u + 1] = A[:u + 1][::-1]
            res.append(i)
            A[:i] = A[:i][::-1]
        return res
