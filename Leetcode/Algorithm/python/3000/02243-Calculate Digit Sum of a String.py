class Solution(object):
    def digitSum(self, s, k):
        while len(s) > k:
            n = len(s)
            ss = ''
            for i in xrange(0, n, k):
                u = sum(map(int, s[i: i + k]))
                ss += str(u)
            s = ss
        return s
