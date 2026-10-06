class Solution(object):
    def maxPointsInsideSquare(self, points, s):
        l, r = 0, 1234567890
        maxi = 0
        while l < r:
            m = (l + r) / 2
            st = set()
            flag = False
            for i, (x, y) in enumerate(points):
                if max(abs(x), abs(y)) <= m:
                    c = s[i]
                    if c in st:
                        flag = True
                        break
                    else:
                        st.add(c)
            if not flag:
                maxi = max(maxi, len(st))
                l = m + 1
            else:
                r = m
        return maxi
