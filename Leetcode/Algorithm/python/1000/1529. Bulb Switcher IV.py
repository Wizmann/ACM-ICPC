class Solution(object):
    def minFlips(self, target):
        target = map(int, target)
        status = 0
        cnt = 0
        for num in target:
            if num ^ status == 0:
                pass
            else:
                status ^= 1
                cnt += 1
        return cnt
