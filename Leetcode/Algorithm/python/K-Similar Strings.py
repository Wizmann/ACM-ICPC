class Solution(object):
    def kSimilarity(self, A, B):
        self.ans = 10 ** 10
        self.dfs(0, list(A), list(B), 0)
        return self.ans

    def dfs(self, cur, A, B, step):
        if cur == len(A):
            self.ans = min(self.ans, step)
            return

        if step >= self.ans:
            return

        if A[cur] == B[cur]:
            self.dfs(cur + 1, A, B, step)
            return

        c1, c2 = A[cur], B[cur]
        for i in xrange(cur + 1, len(A)):
            if A[i] == c2 and A[i] != B[i]:
                A[cur], A[i] = A[i], A[cur]
                self.dfs(cur + 1, A, B, step + 1)
                A[cur], A[i] = A[i], A[cur]
