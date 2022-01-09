class Solution(object):
    def longestOnes(self, A, K):
        st = []
        n = len(A)
        ans = 0
        cnt0 = 0
        for i in xrange(n):
            st.append(A[i])
            if A[i] == 0:
                cnt0 += 1
                
            if cnt0 <= K:
                ans = max(ans, len(st))
            else:
                while st and cnt0 > K:
                    front = st.pop(0)
                    if front == 0:
                        cnt0 -= 1
                ans = max(ans, len(st))
        return ans
