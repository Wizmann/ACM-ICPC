INF = 10 ** 10

class Solution(object):
    def reverse_digit(self, x):
        return int(str(x)[::-1])

    def minMirrorPairDistance(self, nums):
        d = {}
        mini = INF
        for i, num in enumerate(nums):
            r = self.reverse_digit(num)
            if num in d:
                mini = min(mini, i - d[num])
            d[r] = i
        if mini == INF:
            mini = -1
        return mini
