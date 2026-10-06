INF = 10 ** 10

class Solution(object):
    def maximumScore(self, nums, k):
        st = []
        nums.append(-INF)
        res = 0
        for i, num in enumerate(nums):
            while st and num < nums[st[-1]]:
                u = nums[st.pop()]
                l = 0 if not st else st[-1] + 1
                r = i - 1
                if l <= k <= r:
                    # print l, r, nums[st[-1]]
                    res = max(res, (r - l + 1) * u)
            st.append(i)

        return res
