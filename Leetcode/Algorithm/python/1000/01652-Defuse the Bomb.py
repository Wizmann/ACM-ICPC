class Solution(object):
    def decrypt(self, code, k):
        n = len(code)
        res = [0 for i in xrange(n)]
        
        for i in xrange(n):
            cur = 0
            if k > 0:
                for j in xrange(k):
                    cur += code[(i + j + 1) % n]
            elif k < 0:
                for j in xrange(-k):
                    cur += code[(i - 1 - j + n) % n]
            res[i] = cur
            # print res
        return res
                    
