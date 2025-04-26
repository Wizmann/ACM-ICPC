class Solution(object):
    def minAreaRect(self, points):
        st = set()
        for (y, x) in points:
            st.add((y, x))
            
        ans = 10 ** 10
        n = len(points)
        for i in xrange(n):
            (y0, x0) = points[i]
            for j in xrange(i + 1, n):
                (y1, x1) = points[j]
                s = abs(y1 - y0) * abs(x1 - x0)
                if s >= ans:
                    continue
                if y0 == y1 or x0 == x1:
                    continue
                if (y0, x1) not in st or (y1, x0) not in st:
                    continue
                ans = min(ans, s)
        if ans == 10 ** 10:
            ans = 0
        return ans
                    
            
