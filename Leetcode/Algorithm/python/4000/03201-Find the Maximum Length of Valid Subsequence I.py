class Solution(object):
    def maximumLength(self, nums):
        nums = map(lambda x : x % 2, nums)
        n = len(nums)
        ans = max(nums.count(0), nums.count(1))

        nxt0, cnt0 = 0, 0
        nxt1, cnt1 = 1, 0
        for i in xrange(n):
            if nums[i] == nxt0:
                nxt0 ^= 1
                cnt0 += 1
            if nums[i] == nxt1:
                nxt1 ^= 1
                cnt1 += 1
        return max(ans, cnt0, cnt1)
