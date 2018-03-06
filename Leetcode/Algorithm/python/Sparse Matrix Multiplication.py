class Solution(object):
    def multiply(self, A, B):
        n = len(A)
        m = len(B)
        p = len(B[0])
        
        da = {}
        db = {}
        
        for i in xrange(n):
            for j in xrange(m):
                if A[i][j]:
                    if i not in da:
                        da[i] = {}
                    da[i][j] = A[i][j]
        
        for j in xrange(p):
            for i in xrange(m):
                if B[i][j]:
                    if j not in db:
                        db[j] = {}
                    db[j][i] = B[i][j]
                    
        res = [ [0 for i in xrange(p)] for j in xrange(n) ]

        for i in xrange(n):
            if i not in da:
                continue
            for j in xrange(p):
                if j not in db:
                    continue
                for key in set(da[i].keys()) & set(db[j].keys()):
                    res[i][j] += da[i][key] * db[j][key]
        return res
