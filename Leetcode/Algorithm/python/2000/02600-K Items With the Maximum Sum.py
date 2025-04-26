class Solution(object):
    def kItemsWithMaximumSum(self, numOnes, numZeros, numNegOnes, k):
        tot = 0
        a = min(k, numOnes)
        tot += a
        k -= a
        b = min(k, numZeros)
        k -= b
        c = min(k, numNegOnes)
        tot -= c
        k -= c
        return tot
