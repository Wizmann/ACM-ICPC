class Solution(object):
    def minNumberOperations(self, target):
        pre = 0
        cnt = 0
        for num in target:
            u = num - pre
            if u > 0:
                cnt += u
            pre = num
        return cnt
