from collections import defaultdict, Counter

INF = 10 ** 10

class Solution(object):
    def canDistribute(self, nums, quantity):
        m = len(quantity)
        self.m = m
        self.cnts = Counter(nums).values()
        self.cnts.sort(reverse=True)
        self.cnts = [-INF] + self.cnts[:m][::-1]
        self.quantity = quantity
        self.quantity.sort()
        self.dp = [ [-1 for j in xrange(1 << m)] for i in xrange(len(self.cnts)) ]
        
        return self.dfs(len(self.cnts) - 1, (1 << m) - 1)
    
    def count(self, sub):
        res = 0
        for i in xrange(self.m):
            if sub & (1 << i):
                res += self.quantity[i]
        return res
    
    def dfs(self, cnt, customers):
        if customers == 0:
            return True
        if cnt < 0:
            return False
        if self.dp[cnt][customers] != -1:
            return self.dp[cnt][customers]
        
        sub = customers
        while sub:
            tot = self.count(sub)
            if tot <= self.cnts[cnt]:
                if self.dfs(cnt - 1, customers ^ sub):
                    self.dp[cnt][customers] = True
                    return True
            sub = (sub - 1) & customers
        self.dp[cnt][customers] = False
        return self.dp[cnt][customers]
