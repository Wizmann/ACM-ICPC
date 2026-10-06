class Solution(object):
    def countOdds(self, low, high):
        if low % 2 == 0:
            low += 1
        return max(0, (high - low) / 2 + 1)
