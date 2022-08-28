class Solution(object):
    def minimumOperations(self, nums):
        cnt = 0
        while nums and sum(nums):
            nums = filter(lambda x: x, nums)
            mini = min(nums)
            nums = map(lambda x: x - mini, nums)
            cnt += 1
        return cnt
