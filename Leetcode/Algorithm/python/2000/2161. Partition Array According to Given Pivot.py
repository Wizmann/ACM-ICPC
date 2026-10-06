INF = 10 ** 7
MAXI = 10 ** 6

class Solution(object):
    def pivotArray(self, nums, pivot):
        n = len(nums)
        def pre(idx, num):
            if num > pivot:
                return num + INF * (idx + 1)
            elif num < pivot:
                return num - INF * (n - idx + 1)
            else:
                return pivot
        for i in xrange(n):
            nums[i] = pre(i, nums[i])
        nums.sort()
        for i in xrange(n):
            x = nums[i]
            nums[i] = x % INF - INF if x % INF > MAXI else x % INF
        return nums
