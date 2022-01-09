class Solution(object):
    def kidsWithCandies(self, candies, extra):
        maxi = max(candies)
        return [c + extra >= maxi for c in candies]
