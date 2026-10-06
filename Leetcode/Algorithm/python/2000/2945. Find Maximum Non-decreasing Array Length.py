INF = 2 ** 63

class Solution(object):
    def findMaximumLength(self, nums):
        nums = [0] + nums
        n = len(nums)

        presum = nums
        for i in xrange(1, n):
            presum[i] += presum[i - 1]

        dp = [(-1, -1) for i in xrange(n)]
        # sum, item cnt
        dp[0] = (0, 0)
        st = [0]
        for i in xrange(1, n):
            l, r = 1, len(st) - 1

            while l <= r:
                m = (l + r) / 2
                p = st[m]
                s = presum[i]
                if s >= dp[p][0]:
                    l = m + 1
                else:
                    r = m - 1
            cur = (presum[i] + presum[i] - presum[st[r]], dp[st[r]][1] + 1)
            dp[i] = cur

            while st:
                if cur[0] < dp[st[-1]][0]:
                    st.pop()
                else:
                    break
            st.append(i)
        return dp[-1][-1]

# assert Solution().findMaximumLength([546,575,247,650,178,752,356,318,131,438]) == 5
# assert Solution().findMaximumLength([147,633,535,183,886]) == 4
# assert Solution().findMaximumLength([336,78,256,976,976,764,370,46]) == 4
# assert Solution().findMaximumLength([4,3,2,6]) == 3
# assert Solution().findMaximumLength([5,2,2]) == 1
