class Solution(object):
    def reverseStr(self, s, k):
        n = len(s)
        s = list(s)
        for i in xrange(0, n, 2 * k):
            s[i: i + k] = s[i: i + k][::-1]
        return ''.join(s)
