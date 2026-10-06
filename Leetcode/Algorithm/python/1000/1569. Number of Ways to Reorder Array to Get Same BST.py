MOD = (10 ** 9) + 7

def C(a, b):
    res = 1
    for i in xrange(a):
        res = (res * (b - i)) % MOD
    for i in xrange(a):
        res = (res * pow(i + 1, MOD - 2, MOD)) % MOD
    return res

class Solution(object):
    def numOfWays(self, nums):
        return self.solve(nums) - 1

    def solve(self, nums):
        if len(nums) == 0:
            return 1
        cur = nums[0]
        lt = filter(lambda x: x < cur, nums)
        gt = filter(lambda x: x > cur, nums)
        
        c = C(len(lt), len(nums) - 1) % MOD
        return c * self.solve(lt) * self.solve(gt) % MOD
