INF = 10 ** 10

class Solution(object):
    def binaryGap(self, N):
        res = 0
        cnt = -INF
        while N:
            if N % 2 == 1:
                res = max(res, cnt + 1)
                cnt = 0
            else:
                cnt += 1
            N /= 2
        return res
