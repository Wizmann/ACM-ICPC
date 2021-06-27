INF = 10 ** 10

class Solution(object):
    def canBeIncreasing(self, nums):
        count = 0
        nums = [-INF] + nums
        for i, num in enumerate(nums):
            if i == 0:
                continue
            if num <= nums[i - 1]:
                if count > 0:
                    return False
                if nums[i] <= nums[i - 2]:
                    nums[i] = nums[i - 1]
                    count += 1
                else:
                    count += 1
            # print i, count
            if count > 1:
                return False
        return True
