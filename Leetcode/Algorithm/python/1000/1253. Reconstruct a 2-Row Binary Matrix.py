class Solution(object):
    def reconstructMatrix(self, upper, lower, colsum):
        if upper + lower != sum(colsum):
            return []
        n = len(colsum)
        res = [ [0 for i in xrange(n)] for j in xrange(2) ]
        for i, num in enumerate(colsum):
            if num == 2:
                res[0][i] = 1
                res[1][i] = 1
                upper -= 1
                lower -= 1
        if upper < 0 or lower < 0:
            return []
        for i, num in enumerate(colsum):
            if num == 1:
                if upper:
                    res[0][i] = 1
                    upper -= 1
                else:
                    res[1][i] = 1
                    lower -= 1
        return res
                
