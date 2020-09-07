class Solution(object):
    def getLastMoment(self, n, left, right):
        maxi = 0
        for ant in right:
            maxi = max(maxi, n - ant)
        for ant in left:
            maxi = max(maxi, ant)
        return maxi
