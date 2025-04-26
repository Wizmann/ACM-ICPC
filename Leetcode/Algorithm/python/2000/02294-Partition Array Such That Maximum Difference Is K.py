class Solution(object):
    def partitionArray(self, nums, k):
        nums.sort()
        pre = nums[0]
        cnt = 1
        for num in nums:
            if num - pre > k:
                pre = num
                cnt += 1
        return cnt
