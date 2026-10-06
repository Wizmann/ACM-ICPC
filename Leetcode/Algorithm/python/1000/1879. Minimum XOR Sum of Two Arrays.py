INF = 10 ** 10

class Solution(object):
    def minimumXORSum(self, nums1, nums2):
        self.nums1 = nums1
        self.nums2 = nums2
        self.n = len(nums1)
        self.dp = {}
        
        return self.dfs(0, 0)
        
    def dfs(self, a, b):
        key = (a, b)
        if key in self.dp:
            return self.dp[key]
        if a == (1 << self.n) - 1:
            assert a == b
            return 0
        res = INF
        for i in xrange(self.n):
            if a & (1 << i):
                continue
            for j in xrange(self.n):
                if b & (1 << j):
                    continue
                aa = a | (1 << i)
                bb = b | (1 << j)
                
                res = min(res, self.dfs(aa, bb) + (self.nums1[i] ^ self.nums2[j]))
            break
                
        self.dp[key] = res
        return res
