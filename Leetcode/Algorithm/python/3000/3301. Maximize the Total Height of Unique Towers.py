INF = 10 ** 10

class Solution(object):
    def maximumTotalSum(self, maximumHeight):
        tot = 0
        maxi = INF
        maximumHeight.sort(reverse=True)
        for h in maximumHeight:
            maxi = min(maxi - 1, h)
            tot += maxi
            if maxi <= 0:
                return -1
        return tot
