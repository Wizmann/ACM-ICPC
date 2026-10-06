class Solution(object):
    def arithmeticTriplets(self, nums, diff):
        st = set(nums)
        cnt = 0
        for num in nums:
            if num + diff in st and num + 2 * diff in st:
                cnt += 1
        return cnt
