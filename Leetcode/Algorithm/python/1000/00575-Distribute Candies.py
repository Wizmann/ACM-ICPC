class Solution(object):
    def distributeCandies(self, candies):
        s = set(candies)
        return min(len(candies) / 2, len(s))
