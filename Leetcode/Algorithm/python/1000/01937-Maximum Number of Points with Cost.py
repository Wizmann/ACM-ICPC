INF = 10 ** 10

class Solution(object):
    def maxPoints(self, points):
        n = len(points)
        m = len(points[0])
        
        for i in xrange(1, n):
            dp = [-INF for x in xrange(m)]
            
            st = []
            for j in xrange(m):
                while st and points[i - 1][st[-1]] - abs(j - st[-1]) <= points[i - 1][j]:
                    st.pop()
                st.append(j)
                dp[j] = max(dp[j], points[i - 1][st[0]] + points[i][j] - abs(j - st[0]))
                
            st = []
            for j in xrange(m - 1, -1, -1):
                while st and points[i - 1][st[-1]] - abs(j - st[-1]) <= points[i - 1][j]:
                    st.pop()
                st.append(j)
                dp[j] = max(dp[j], points[i - 1][st[0]] + points[i][j] - abs(j - st[0]))
            points[i] = dp
        return max(points[-1])

