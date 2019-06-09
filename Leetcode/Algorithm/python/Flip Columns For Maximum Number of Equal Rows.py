from collections import defaultdict

class Solution(object):
    def maxEqualRowsAfterFlips(self, matrix):
        d = defaultdict(int)
        for line in matrix:
            key = ''.join(map(str, line))
            d[key] += 1
            
        res = 0
        for key, value in d.items():
            k1 = key
            k2 = self.flip(key)
            
            res = max(res, d[k1] + d[k2])
        return res
    
    def flip(self, key):
        res = ''
        for c in key:
            if c == '0':
                res += '1'
            else:
                res += '0'
        return res
