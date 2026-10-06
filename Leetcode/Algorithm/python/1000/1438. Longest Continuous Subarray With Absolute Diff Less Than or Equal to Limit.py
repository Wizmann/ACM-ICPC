class Solution(object):
    def longestSubarray(self, nums, limit):
        st1, st2 = [], []
        pre = 0
        res = 0
        for i, num in enumerate(nums):
            while True:
                while st1 and st1[0] < pre:
                    st1.pop(0)
                while st2 and st2[0] < pre:
                    st2.pop(0)
                while st1 and num >= nums[st1[-1]]:
                    st1.pop()
                while st2 and num <= nums[st2[-1]]:
                    st2.pop()
                st1.append(i)
                st2.append(i)
                maxi = nums[st1[0]]
                mini = nums[st2[0]]
                if maxi - mini > limit:
                    pre += 1
                else:
                    res = max(res, i - pre + 1)
                    break
        return res
