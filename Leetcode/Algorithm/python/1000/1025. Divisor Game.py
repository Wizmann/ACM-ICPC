class Solution(object):
    def divisorGame(self, N):
        self.dp = [-1 for i in xrange(N + 1)]
        return self.sg(N) != 0
    
    def sg(self, N):
        if self.dp[N] != -1:
            return self.dp[N]
        st = set()
        for i in xrange(1, N):
            if N % i == 0:
                st.add(self.sg(N - i))
        self.dp[N] = self.mex(st)
        return self.dp[N]
        
    def mex(self, ns):
        if not ns:
            return 0
        for i in xrange(0, max(ns)):
            if i not in ns:
                return i
        return max(ns) + 1
