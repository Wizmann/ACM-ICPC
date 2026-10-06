class Solution(object):
    def countCommas(self, n):
        # A number with d digits contributes (d-1)//3 commas.
        # Equivalently, sum over k=1,2,... of count(numbers in [0,n] with >= 3k+1 digits)
        # = sum over k of count(numbers >= 10^(3k))
        cnt = 0
        threshold = 1000  # 10^3
        while threshold <= n:
            cnt += n - threshold + 1
            threshold *= 1000
        return cnt
