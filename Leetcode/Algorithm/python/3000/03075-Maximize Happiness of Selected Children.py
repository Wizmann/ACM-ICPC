class Solution(object):
    def maximumHappinessSum(self, hs, k):
        hs.sort(reverse=True)
        tot = 0
        for i in xrange(k):
            tot += max(0, hs[i] - i)
        return tot

