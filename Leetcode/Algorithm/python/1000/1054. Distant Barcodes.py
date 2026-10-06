from collections import Counter

class Solution(object):
    def rearrangeBarcodes(self, barcodes):
        n = len(barcodes)
        c = sorted(Counter(barcodes).items(), key=lambda x: x[1], reverse=True)
        
        res = [-1 for i in xrange(n)]
        idx = 0
        for (k, v) in c:
            for i in xrange(v):
                res[idx] = k
                idx += 2
                if idx >= n:
                    idx = 1
        return res
