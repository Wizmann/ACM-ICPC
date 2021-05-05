INF = 10 ** 10

class Solution(object):
    def maxRepeating(self, sequence, word):
        maxi = 0
        for i in xrange(INF):
            subseq = word * i
            if subseq in sequence:
                maxi = max(maxi, i)
            else:
                break
        return maxi
