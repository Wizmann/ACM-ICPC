class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        d = {}
        n = len(text1)
        m = len(text2)
        
        for i in xrange(1, n + 1):
            for j in xrange(1, m + 1):
                if text1[i - 1] == text2[j - 1]:
                    pre = (i - 1, j - 1)
                    cur = (i, j)
                    d[cur] = d.get(pre, 0) + 1
                else:
                    cur = (i, j)
                    pre1 = (i - 1, j - 1)
                    pre2 = (i, j - 1)
                    pre3 = (i - 1, j)
                    d[cur] = max([d.get(pre, 0) for pre in [pre1, pre2, pre3]])
        #print d
        return max(d.values())
