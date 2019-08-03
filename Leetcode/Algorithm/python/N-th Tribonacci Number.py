class Solution(object):
    def tribonacci(self, n):
        T = [0, 1, 1]
        for i in xrange(3, n + 1):
            u = T[i - 1] + T[i - 2] + T[i - 3]
            T.append(u)
        return T[n]
