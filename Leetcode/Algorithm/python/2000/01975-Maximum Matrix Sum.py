class Solution(object):
    def maxMatrixSum(self, matrix):
        nums = []
        neg = 0
        for line in matrix:
            for num in line:
                if num > 0:
                    nums.append(num)
                else:
                    neg += 1
                    nums.append(-num)
        if neg % 2 == 0:
            return sum(nums)
        else:
            nums.sort()
            # print nums
            return sum(nums[1:]) - nums[0]
