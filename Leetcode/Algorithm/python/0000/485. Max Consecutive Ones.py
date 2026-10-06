class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        if not nums:
            return 0
            
        pre = 0
        cnt = 0
        ans = 0
        for num in nums:
            if num == 0:
                pre = 0
                ans = max(ans, cnt)
                cnt = 0
            else:
                if pre == 1:
                    cnt += 1
                elif pre == 0:
                    pre = 1
                    cnt = 1
        return max(ans, cnt)
                
