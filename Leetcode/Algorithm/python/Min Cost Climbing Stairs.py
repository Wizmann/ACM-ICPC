class Solution(object):
    def minCostClimbingStairs(self, cost):
        cost.append(0)
        n = len(cost)
        if n < 2:
            return 0
        
        for i in xrange(2, n):
            cost[i] += min(cost[i - 2], cost[i - 1])
        return cost[-1]
        
        
