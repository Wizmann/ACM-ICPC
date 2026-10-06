class Solution(object):
    def subarraySum(self, nums, k):
        d = {0: 1}

        res = 0
        s = 0
        for num in nums:
            s += num
            delta = s - k
            res += d.get(delta, 0)
            d[s] = d.get(s, 0) + 1
        return res

print Solution().subarraySum([1,1,1], 2)
print Solution().subarraySum([1,1], 2)
print Solution().subarraySum([1,2,1], 2)
print Solution().subarraySum([0,2,0], 2)
print Solution().subarraySum([], 2)
