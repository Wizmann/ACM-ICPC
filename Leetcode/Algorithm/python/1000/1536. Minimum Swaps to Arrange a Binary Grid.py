class Solution(object):
    def minSwaps(self, grid):
        nums = []
        for line in grid:
            nums.append(int(''.join(map(str, line)[::-1]), 2))
        n = len(grid)
        m = len(grid[0])
        res = 0
        for i in xrange(n):
            mask = ((1 << m) - 1) ^ ((1 << (i + 1)) - 1)
            # print mask, nums
            for j, num in enumerate(nums):
                if (num & mask) == 0:
                    res += j
                    del nums[j]
                    break
            else:
                return -1
        return res
            
