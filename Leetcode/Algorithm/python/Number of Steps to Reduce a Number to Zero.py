# https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
 
class Solution:
    def numberOfSteps (self, num: int) -> int:
        cnt = 0
        while num:
            if num % 2 == 0:
                num = num / 2
            else:
                num = num - 1
            cnt += 1
        return cnt
