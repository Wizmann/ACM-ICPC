class Solution(object):
    def findDifferentBinaryString(self, nums):
        nums.sort()
        n = len(nums[0])
        fmt = u'{:0%db}' % n
        for i, num in enumerate(nums):
            u = int(num, 2)
            if i != u:
                return fmt.format(i)
        return fmt.format((1 << n) - 1)
