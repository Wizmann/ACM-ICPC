class Solution(object):
    def maxScore(self, cardPoints, k):
        n = len(cardPoints)
        pre = [0 for i in xrange(n)]
        suf = [0 for i in xrange(n)]
        
        for i in xrange(n):
            pre[i] += cardPoints[i]
            if i - 1 >= 0:
                pre[i] += pre[i - 1]
                
        for i in xrange(n - 1, -1, -1):
            suf[i] += cardPoints[i]
            if i + 1 < n:
                suf[i] += suf[i + 1]
        #print pre
        #print suf
        res = 0
        for i in xrange(0, k + 1):
            left = 0 if i == 0 else pre[i - 1]
            right = 0 if k - i == 0 else suf[n - (k - i)]
            # print i - 1, n - (k - i)
            res = max(res, left + right)
        return res
