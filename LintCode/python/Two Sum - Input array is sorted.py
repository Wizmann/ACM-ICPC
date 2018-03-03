class Solution:
    """
    @param nums: an array of Integer
    @param target: target = nums[index1] + nums[index2]
    @return: [index1 + 1, index2 + 1] (index1 < index2)
    """
    def twoSum(self, nums, target):
        n = len(nums)
        p, q = 0, n - 1
        while p < q:
            if nums[p] + nums[q] < target:
                p += 1
            elif nums[p] + nums[q] > target:
                q -= 1
            else:
                return [p + 1, q + 1]
        return []
