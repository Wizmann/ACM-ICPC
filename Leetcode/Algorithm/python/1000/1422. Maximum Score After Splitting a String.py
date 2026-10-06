class Solution(object):
    def maxScore(self, s):
        ones = s.count('1')
        n = len(s)
        left = 0
        right = ones
        res = 0
        for i in xrange(n - 1):
            if s[i] == '0':
                left += 1
            else:
                right -= 1
            res = max(res, left + right)
        return res
