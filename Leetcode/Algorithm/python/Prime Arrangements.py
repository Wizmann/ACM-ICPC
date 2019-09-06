MOD = (10 ** 9) + 7

class Solution(object):
    def numPrimeArrangements(self, n):
        ps = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
        
        lt = len(filter(lambda x: x <= n, ps))
        rt = n - lt
        res = 1
        for i in xrange(1, lt + 1):
            res = (res * i) % MOD
        for i in xrange(1, rt + 1):
            res = (res * i) % MOD
        return res
