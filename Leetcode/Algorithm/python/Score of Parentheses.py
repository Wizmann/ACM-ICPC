class Solution(object):
    def scoreOfParentheses(self, S):
        self.d = {}
        self.n = len(S)
        self.S = S
        
        cnt = 0
        st = []
        for i in xrange(self.n):
            if S[i] == '(':
                st.append(i)
            else:
                u = st.pop()
                self.d[u] = i
        print self.d
        print S
        if self.d[0] == self.n - 1:
            return self.dfs(0, self.n)
        else:
            return Solution().scoreOfParentheses('(' + S + ')') / 2
    
    def dfs(self, l, r):
        print l, r
        if l + 2 == r:
            return 1
        l += 1
        r -= 1
        
        if self.d[l] == r - 1:
            return 2 * self.dfs(l, r)
        
        u = 0
        p = l
        while p < r - 1:
            q = self.d[p]
            u += self.dfs(p, q + 1)
            p = q + 1
        return u * 2
