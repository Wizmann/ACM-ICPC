class Solution(object):
    def shortestBridge(self, A):
        n = len(A)
        m = len(A[0])
        self.n = n
        self.m = m
        
        pa, pb = [], []
        for i in xrange(n):
            for j in xrange(m):
                if A[i][j] != 1:
                    continue
                if not pa:
                    self.dfs(A, i, j, pa)
                elif not pb:
                    self.dfs(A, i, j, pb)
                else:
                    break
        ans = 10 ** 10
        pb.sort()
        for p in pa:
            l, r = 0, len(pb) - 1
            while l <= r:
                m = (l + r) >> 1
                if p[0] - pb[m][0] >= ans:
                    l = m + 1
                else:
                    r = m - 1
            for q in pb[max(r, 0):]:
                if q[0] - p[0] >= ans:
                    break
                ans = min(ans, abs(p[0] - q[0]) + abs(p[1] - q[1]))
        return ans - 1
    
    def dfs(self, A, y, x, st):
        A[y][x] = -1
        
        cnt = 0
        for (my, mx) in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            ny = y + my
            nx = x + mx
            
            if 0 <= ny < self.n and 0 <= nx < self.m:
                if A[ny][nx] == 1:
                    self.dfs(A, ny, nx, st)
                elif A[ny][nx] != 0:
                    cnt += 1
        if cnt < 4:
            st.append((y, x))
                
