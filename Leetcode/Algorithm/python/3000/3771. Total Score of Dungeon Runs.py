import bisect

class Solution(object):
    def totalScore(self, hp, damage, requirement):
        n = len(damage)

        pre = [0] * (n + 1)
        for i in range(n):
            pre[i + 1] = pre[i] + damage[i]

        ans = 0

        for r in range(n):
            limit = pre[r + 1] - (hp - requirement[r])

            l = bisect.bisect_left(pre, limit, 0, r + 1)

            if l <= r:
                ans += r - l + 1

        return ans
