MOD = (10 ** 9) + 7

class Solution(object):
    def numSubseq(self, nums, target):
        n = len(nums)
        res = 0
        nums.sort()
        p, q = 0, n - 1

        while q >= 0:
            if nums[q] * 2 <= target:
                res += 1
            p = min(p, q - 1)
            p = max(0, p)
            while p < q and nums[p] + nums[q] <= target:
                p += 1
            res += self.calc(q) - self.calc(q - p)
            res = (res % MOD + MOD) % MOD
            q -= 1
        return res
    
    def calc(self, n):
        if n < 0:
            return 0
        return (pow(2, n, MOD) - 1 + MOD) % MOD
        
