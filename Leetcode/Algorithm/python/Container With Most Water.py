class Solution:
    # @return an integer
    def maxArea(self, height):
        n = len(height)
        l, r = 0, n - 1
        ans = 0
        while l < r:
            dis = r - l 
            ans = max(ans, min(height[l], height[r]) * dis)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans
