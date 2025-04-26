class Solution(object):
    def champagneTower(self, poured, query_row, query_glass):
        glasses = [ [0 for i in xrange(j + 1)] for j in xrange(query_row + 2) ]
        glasses[0][0] = poured
        
        for i in xrange(query_row + 1):
            for j in xrange(i + 1):
                if glasses[i][j] > 1.0:
                    ex = glasses[i][j] - 1.0
                    glasses[i][j] = 1.0
                    glasses[i + 1][j] += ex / 2.0
                    glasses[i + 1][j + 1] += ex / 2.0
        return glasses[query_row][query_glass]
