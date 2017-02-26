class Solution(object):
    def checkSubarraySum(self, nums, k):
        d = {0: -1}
        prefix = 0
        for i, num in enumerate(nums):
            if k:
                prefix = ((prefix + num) % k + k) % k
            else:
                prefix = prefix + num
                
            if prefix in d:
                if i - d[prefix] > 1:
                    return True
            else:
                d[prefix] = i
        return False
        
    def brute_force(self, nums, k):
        n = len(nums)
        for i in xrange(n):
            for j in xrange(i + 1, n):
                u = sum(nums[i: j + 1])
                if u % k == 0:
                    return True
        return False

S = Solution()

assert S.brute_force([19, 23, 4, 6, 7], 23) == True
assert S.brute_force([1, 23, 4, 6, 7], 23) == False
assert S.brute_force([23, 2, 4, 6, 7], 6) == True
assert S.brute_force([23, 2, 6, 4, 7], 6) == True
assert S.brute_force([23, 2, 6, 4, 7], 7) == True
assert S.brute_force([23, 2, 6, 4, 7], 21) == True
assert S.brute_force([-1, -2, -1, -1, -1], 6) == True
assert S.brute_force([-1, -2, -1, -1, -1], 3) == True
assert S.brute_force([-1, -2, -1, -1, -1], 2) == True


assert S.checkSubarraySum([0], 13) == False
assert S.checkSubarraySum([0, 0], 13) == True

assert S.checkSubarraySum([0, 0], 0) == True
assert S.checkSubarraySum([1, -1], 0) == True
assert S.checkSubarraySum([1, 0], 0) == False
assert S.checkSubarraySum([1, 1], 0) == False

assert S.checkSubarraySum([19, 23, 4, 6, 7], 23) == True
assert S.checkSubarraySum([1, 23, 4, 6, 7], 23) == False
assert S.checkSubarraySum([23, 2, 4, 6, 7], 6) == True
assert S.checkSubarraySum([23, 2, 6, 4, 7], 6) == True
assert S.checkSubarraySum([23, 2, 6, 4, 7], 7) == True
assert S.checkSubarraySum([23, 2, 6, 4, 7], 21) == True
assert S.checkSubarraySum([-1, -2, -1, -1, -1], 6) == True
assert S.checkSubarraySum([-1, -2, -1, -1, -1], 3) == True
assert S.checkSubarraySum([-1, -2, -1, -1, -1], 2) == True
