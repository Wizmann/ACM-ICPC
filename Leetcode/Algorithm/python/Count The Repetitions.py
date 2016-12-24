class Solution(object):
    def getMaxRepetitions(self, s1, n1, s2, n2):
        if not set(s2) <= set(s1):
            return 0
        l1, l2 = len(s1), len(s2)
        dp = collections.defaultdict(dict)
        x1 = x2 = 0
        while x1 < l1 * n1:
            while s1[x1 % l1] != s2[x2 % l2]:
                x1 += 1
            if x1 >= l1 * n1:
                break
            y1, y2 = x1 % l1, x2 % l2
            if y2 not in dp[y1]:
                dp[y1][y2] = x1, x2
            else:
                dx1, dx2 = dp[y1][y2]
                loop = (l1 * n1 - dx1) / (x1 - dx1)
                x1 = dx1 + loop * (x1 - dx1)
                x2 = dx2 + loop * (x2 - dx2)
            if x1 < l1 * n1:
                x1 += 1
                x2 += 1
        return x2 / (n2 * l2)
