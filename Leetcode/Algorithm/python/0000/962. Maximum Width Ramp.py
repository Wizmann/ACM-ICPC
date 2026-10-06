INF = 10 ** 10
class Solution(object):
    def maxWidthRamp(self, A):
        n = len(A)
        B = sorted(zip(A, range(n)))
        mini = INF
        ans = 0
        for (_, pos) in B:
            ans = max(ans, pos - mini)
            mini = min(mini, pos)
        return ans
