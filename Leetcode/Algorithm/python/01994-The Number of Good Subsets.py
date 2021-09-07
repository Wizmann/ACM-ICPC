from collections import Counter

MOD = (10 ** 9) + 7

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

primeid = {}

for i, prime in enumerate(primes):
    primeid[prime] = i

class Solution(object):
    def numberOfGoodSubsets(self, nums):
        nums = Counter(nums).items()
        self.dp = {}
        return self.dfs(0, 0, nums)
    
    def dfs(self, cur, status, nums):
        if cur == len(nums):
            return 1 if status else 0
        
        if (cur, status) in self.dp:
            return self.dp[(cur, status)]
        
        res = 0
        num, cnt = nums[cur]
        
        cur_status = 0
        for prime in primes:
            if num % prime == 0:
                cur_status |= 1 << primeid[prime]
            if num % (prime * prime) == 0:
                cur_status = -1
                break
        
        if cur_status >= 0 and (cur_status & status) == 0:
            if num == 1:
                u = (pow(2, cnt, MOD) + MOD - 1) % MOD
            else:
                u = cnt
            res += u * self.dfs(cur + 1, status | cur_status, nums)
        res += self.dfs(cur + 1, status, nums)
        
        res %= MOD
        
        self.dp[(cur, status)] = res
        return res
