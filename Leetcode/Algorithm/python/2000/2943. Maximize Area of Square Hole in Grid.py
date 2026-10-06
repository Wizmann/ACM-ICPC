INF = 10 ** 10

class Solution(object):
    def maximizeSquareHoleArea(self, n, m, hBars, vBars):
        hBars.sort()
        vBars.sort()
        res = min(self.calc(hBars), self.calc(vBars))
        return res ** 2

    def calc(self, bars):
        pre = -INF
        maxi = 1
        cnt = 0
        for b in bars + [INF]:
            if b != pre + 1:
                maxi = max(maxi, cnt + 1)
                cnt = 0    
            pre = b
            cnt += 1
        return maxi
