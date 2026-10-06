MOD = (10 ** 9) + 7

class Solution(object):
    def numFactoredBinaryTrees(self, A):
        self.nums = set(A)
        self.d = {}
        ans = 0
        for num in sorted(A):
            ans += self.solve(num)
            ans %= MOD
        return ans % MOD
    
    def solve(self, root):
        if root in self.d:
            return self.d[root]
        
        res = 1
        for num in filter(lambda x: x < root, self.nums):
            if root % num == 0 and root / num in self.nums:
                a = self.solve(num)
                b = self.solve(root / num)
                res = (res + a * b) % MOD
        self.d[root] = res % MOD
        return self.d[root]
        
        
