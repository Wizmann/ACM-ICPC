class Solution(object):
    def canSeePersonsCount(self, heights):
        st = []
        n = len(heights)
        res = [0 for i in xrange(n)]
        for i in xrange(n - 1, -1, -1):
            cnt = 0
            while st and heights[i] >= st[-1]:
                cnt += 1
                st.pop()
            res[i] = cnt + (1 if st else 0)
            st.append(heights[i])
        return res
