class Solution(object):
    def sortedSquares(self, A):
        return sorted(map(lambda x: x * x, A))
