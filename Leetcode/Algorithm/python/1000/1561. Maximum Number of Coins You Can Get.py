class Solution(object):
    def maxCoins(self, piles):
        n = len(piles)
        return sum(sorted(piles)[n / 3::][::-1][1::2])
