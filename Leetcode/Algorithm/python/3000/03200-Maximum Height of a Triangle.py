class Solution(object):
    def maxHeightOfTriangle(self, red, blue):
        return max(self.solve(red, blue), self.solve(blue, red))

    def solve(self, a, b):
        cnt = 0
        while True:
            if cnt % 2 == 0:
                a -= (cnt + 1)
            else:
                b -= (cnt + 1)
            if a < 0 or b < 0:
                break
            cnt += 1
        return cnt
