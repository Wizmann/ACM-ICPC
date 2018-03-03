class Solution:
    """
    @param n: a decimal number
    @param k: a Integer represent base-k
    @return: a base-k number
    """
    def hexConversion(self, n, k):
        if n == 0:
            return '0'
        res = ''
        while n:
            u = n % k
            res = '%X' % u + res
            n /= k
        return res
