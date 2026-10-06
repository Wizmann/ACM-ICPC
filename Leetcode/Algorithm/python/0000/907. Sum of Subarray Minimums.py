INF = 10 ** 10
MOD = (10 ** 9) + 7

class Solution(object):
    def sumSubarrayMins(self, A):
        A.append(-INF)
        st = []
        ans = 0
        for i, num in enumerate(A):
            while st and A[st[-1]] > num:
                cur = st.pop()
                l = cur - (-1 if not st else st[-1])
                r = i - cur
                ans = (ans + l * r * A[cur]) % MOD
            st.append(i)
        return ans
