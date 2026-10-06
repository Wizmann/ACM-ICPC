class Solution(object):
    def maximumWealth(self, accounts):
        return max(map(sum, accounts))
