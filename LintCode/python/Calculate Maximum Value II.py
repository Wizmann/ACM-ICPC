class Solution:
    """
    @param str: a string of numbers
    @return: the maximum value
    """
    def __init__(self):
        self.d = {}
    
    def maxValue(self, str):
        if str in self.d:
            return self.d[str]
            
        if len(str) == 1:
            return int(str)
            
        n = len(str)
        res = 0
        for i in xrange(1, n):
            l, r = str[:i], str[i:]
            vl, vr = self.maxValue(l), self.maxValue(r)
            res = max(res, vl + vr, vl * vr)
            
        self.d[str] = res
        print str, res
        return res
