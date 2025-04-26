class Solution(object):
    def findKthBit(self, n, k):
        return str(self.findKthBit_(n, k - 1))
    
    def findKthBit_(self, n, k):
        m = 2 ** n - 1
        assert k < m
        if n == 1:
            return 0
        if k < m / 2:
            return self.findKthBit_(n - 1, k)
        elif k == m / 2:
            return 1
        else:
            return self.findKthBit_(n - 1, (m - k - 1)) ^ 1
