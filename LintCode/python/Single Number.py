class Solution:
    """
    @param A : an integer array
    @return : a integer
    """
    def singleNumber(self, A):
        return reduce(lambda x, y: x ^ y, A, 0)
