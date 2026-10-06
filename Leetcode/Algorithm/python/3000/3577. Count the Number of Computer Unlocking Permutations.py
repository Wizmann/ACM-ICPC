MOD = int(1e9 + 7)

class Solution(object):
    def countPermutations(self, complexity):
        n = len(complexity)
        res = 1
        mini1 = complexity[0]
        mini2 = min(complexity[1:])
        if mini1 >= mini2:
            return 0 
        for i in xrange(1, n):
            res = (res * i) % MOD
        return res
