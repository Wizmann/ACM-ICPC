INF = 10 ** 10

class Solution(object):
    def totalSteps(self, nums):
        nums.append(INF)
        st = []
        n = len(nums)
        res = 0
        for i, num in enumerate(nums):
            maxi = 0
            while st and nums[st[-1][0]] <= num:
                pre = st.pop()
                maxi = max(maxi, pre[1])
            if not st:
                maxi = 0
            else:
                maxi += 1
            # print i, num, maxi
            st.append((i, maxi))
            res = max(res, maxi)
        return res
