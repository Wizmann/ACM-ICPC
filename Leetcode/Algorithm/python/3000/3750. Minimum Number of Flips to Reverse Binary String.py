class Solution(object):
    def minimumFlips(self, n):
        n = '{:b}'.format(n)
        m = n[::-1]
        cnt = 0
        for i in xrange(len(n)):
            if n[i] != m[i]:
                cnt += 1
        return cnt
