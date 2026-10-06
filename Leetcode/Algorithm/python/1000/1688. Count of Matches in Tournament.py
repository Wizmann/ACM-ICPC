class Solution(object):
    def numberOfMatches(self, n):
        return 0 if n == 1 else self.numberOfMatches((n + 1) / 2) + n / 2
