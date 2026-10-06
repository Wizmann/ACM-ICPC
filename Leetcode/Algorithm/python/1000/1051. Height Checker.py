class Solution(object):
    def heightChecker(self, heights):
        s = sorted(heights)
        n = len(heights)
        
        cnt = 0
        for i in xrange(n):
            if s[i] != heights[i]:
                cnt += 1
        return cnt
