INF = 10 ** 10

class Solution(object):
    def findMaxValueOfEquation(self, points, k):
        st = []
        res = -INF
        for i, (x, y) in enumerate(points):
            while st and x - points[st[0]][0] > k:
                st.pop(0)
            if st:
                res = max(res, x + y + points[st[0]][1] - points[st[0]][0])
            while st and points[st[-1]][1] - points[st[-1]][0] <= y - x:
                st.pop()
            st.append(i)
        return res
            
