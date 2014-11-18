class Solution:
    # @param height, a list of integer
    # @return an integer
    def largestRectangleArea(self, height):
        height.append(0)
        st = []
        ans, n = 0, len(height)
        for i in xrange(n):
            if not st or height[st[-1]] < height[i]:
                st.append(i)
                continue
            while st and height[st[-1]] >= height[i]:
                now   = st.pop()
                left  = 0 if not st else st[-1] + 1
                right = i - 1
                ans   = max(ans, height[now] * (right - left + 1))
            st.append(i)
        return ans
