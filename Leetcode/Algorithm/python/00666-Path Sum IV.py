INF = 10 ** 10

class Solution(object):
    def pathSum(self, nums):
        self.tree = [INF for i in xrange(100)]
        self.ans = 0
        
        for num in nums:
            d, p, v = num / 100, num / 10 % 10, num % 10
            nr = (1 << (d - 1)) + p - 1
            self.tree[nr] = v
        self.doPathSum(1, 0)
        return self.ans
    
    def doPathSum(self, cur, prefix):
        if self.tree[cur] == INF:
            return
        
        l = cur * 2
        r = cur * 2 + 1
        
        if self.tree[l] != INF:
            self.doPathSum(l, prefix + self.tree[cur])
        if self.tree[r] != INF:
            self.doPathSum(r, prefix + self.tree[cur])
            
        if self.tree[l] == INF and self.tree[r] == INF:
            self.ans += prefix + self.tree[cur]
      
S = Solution()
assert S.pathSum([113, 215, 221]) == 12
assert S.pathSum([113, 221]) == 4
assert S.pathSum([]) == 0
