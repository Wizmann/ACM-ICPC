class Solution(object):
    def rowAndMaximumOnes(self, mat):
        maxv = -1
        maxi = -1
        
        for i, line in enumerate(mat):
            tot = sum(line)
            if tot > maxv:
                maxv = tot
                maxi = i
        return [maxi, maxv]
