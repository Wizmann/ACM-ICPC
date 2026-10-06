class Solution(object):
    def findMaxLength(self, nums):
        if not nums:
            return 0
        d = {0: -1}
        counter = 0
        ans = 0
        for i, num in enumerate(nums):
            if num == 0:
                counter -= 1;
            else:
                counter += 1

            if counter in d:
                ans = max(ans, i - d[counter])
            d[counter] = min(d.get(counter, i), i)
        return ans
        
        
def brute_force(nums):
    n = len(nums)
    ans = 0
    for i in xrange(n):
        for j in xrange(i + 1, n):
            sl = nums[i: j + 1]
            if sl.count(0) == sl.count(1):
                ans = max(ans, j - i + 1)
    return ans
    
    
S = Solution()

assert(S.findMaxLength([1, 0, 1, 1, 1, 1, 0, 0, 0, 1]) == 8)

assert(S.findMaxLength([0,1]) == 2)
assert(S.findMaxLength([0,1,0]) == 2)
assert(S.findMaxLength([0,1,0,1]) == 4)
assert(brute_force([1, 0, 1, 1, 1, 1, 0, 0, 0, 1]) == 8)
assert(S.findMaxLength([1, 0, 1, 1, 1, 1, 0, 0, 0, 1]) == 8)
assert(brute_force([0,1,0,1]) == 4)


import random

for i in xrange(100):
    nums = [random.choice([0, 1]) for i in xrange(10)]
    assert(S.findMaxLength(nums) == brute_force(nums))
