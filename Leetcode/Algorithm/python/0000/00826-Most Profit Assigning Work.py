class Solution(object):
    def maxProfitAssignment(self, difficulty, profit, workers):
        works = [0 for i in xrange(111111)]
        for p, d in zip(profit, difficulty):
            works[d] = max(works[d], p)
            
        for i in xrange(1, 111111):
            works[i] = max(works[i], works[i - 1])
        
        res = 0
        for worker in workers:
            res += works[worker]
        return res
