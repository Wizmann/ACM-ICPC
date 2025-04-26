class Solution(object):
    def findPermutationDifference(self, s, t):
        t = dict(map(lambda (x, y): (y, x), enumerate(t)))
        ans = 0
        for i, c in enumerate(s):
            ans += abs(i - t[c])
        return ans
