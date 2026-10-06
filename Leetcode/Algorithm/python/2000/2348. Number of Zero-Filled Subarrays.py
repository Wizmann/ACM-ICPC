class Solution(object):
    def zeroFilledSubarray(self, nums):
        nums.append(-1)
        pre = -1
        cnt = 0
        res = 0
        for num in nums:
            if num != pre:
                if pre == 0:
                    res += cnt * (cnt - 1) / 2 + cnt
                pre = num
                cnt = 1
            else:
                cnt += 1
        return res
