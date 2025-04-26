class Solution(object):
    def largestPerimeter(self, nums):
        pre = 0
        nums.sort()
        maxi = 0
        for i, num in enumerate(nums):
            if i and num < pre:
                maxi = max(maxi, num + pre)
            pre += num
        if maxi == 0:
            return -1
        return maxi
            
